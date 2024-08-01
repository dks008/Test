#include "mainwindow.h"
#include <QJsonDocument>
#include <QDebug>
#include <QSslSocket>
#include <QJsonObject>
#include <QJsonArray>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>
#include <QDebug>
#include <QSettings>
#include <QUrl>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , networkManager(new QNetworkAccessManager(this))
    , imagePath("D:\\Backup\\Documents\\My Pictures\\Camera Roll\\0c29197591c062507a6db442f7495dc.png") // ��ʼ��ͼƬ·��
{
    ui->setupUi(this);
    connect(ui->text_recognition_button, &QPushButton::clicked, this, &MainWindow::on_text_recognition_button_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_text_recognition_button_clicked()
{
    QSslSocket::sslLibraryBuildVersionString();
    qDebug() << "SSL Library Build Version:" << QSslSocket::sslLibraryBuildVersionString();
    qDebug() <<"OpenSsL支持情况:"<< QSslSocket::supportsSsl();
    getAccessToken(imagePath);
}

void MainWindow::getAccessToken(const QString& imagePath)
{

    QString apiKey = "MQgLapjtL6kq26P43PDyLZ5c"; // �滻Ϊ���� API Key
    QString secretKey = "jsa7tal5jYHgrMIrIJnj2ZqArC1X3aL2"; // �滻Ϊ���� Secret Key

    QNetworkRequest request(QUrl("https://aip.baidubce.com/oauth/2.0/token"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QByteArray postData;
    postData.append("grant_type=client_credentials");
    postData.append("&client_id=" + apiKey.toUtf8());
    postData.append("&client_secret=" + secretKey.toUtf8());

    qDebug() << "postData:" <<postData;

    QNetworkReply* reply = networkManager->post(request, postData);
    connect(reply, &QNetworkReply::finished, [this, reply]() {
        handleAccessTokenReply(reply);
    });


}

void MainWindow::handleAccessTokenReply(QNetworkReply* reply)
{

    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObj = jsonDoc.object();

        accessToken = jsonObj.value("access_token").toString();
        expiresIn = jsonObj.value("expires_in").toInt();

        qDebug() << "Access Token:" << accessToken;
        qDebug() << "Expires In:" << expiresIn << "seconds";

        sendOCRRequest(imagePath, accessToken);
    }
    else {
        qDebug() << "Access Token Request Error:" << reply->errorString();
    }
    reply->deleteLater();
}

void MainWindow::sendOCRRequest(const QString& imagePath, const QString& accessToken)
{
    QFile file(imagePath);
    if (!file.open(QIODevice::ReadOnly)) {
        ui->text_recognition_output->setText("加油哦~");
        return;
    }

    QByteArray imageData = file.readAll();
    QString base64Image = imageData.toBase64();
    QByteArray urlencodeImage =  QUrl::toPercentEncoding(base64Image);

    QByteArray Image;
    Image.append("image=" + urlencodeImage);

    QNetworkRequest request(QUrl("https://aip.baidubce.com/rest/2.0/ocr/v1/general?access_token=" + accessToken));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QNetworkReply* reply = networkManager->post(request, Image);
    connect(reply, &QNetworkReply::finished, [this, reply]() {
        onReplyFinished(reply); // ʹ�� onReplyFinished ������Ӧ
        qDebug() << "finished";
    });
}

void MainWindow::onReplyFinished(QNetworkReply* reply)
{
    handleOCRResponse(reply); // ���ô�����Ӧ�ĺ���
}

void MainWindow::handleOCRResponse(QNetworkReply* reply)
{
    QString resultText;
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObj = jsonDoc.object();
        qDebug() << "report:" << responseData;
        // ���� OCR ��Ӧ
        if (jsonObj.contains("words_result")) {
            QJsonArray wordsArray = jsonObj["words_result"].toArray();
            for (const QJsonValue& value : wordsArray) {
                resultText += value.toObject()["words"].toString() + "\n";
            }
        }
    }
    else {
        resultText = "����ʧ��: " + reply->errorString();
    }
    qDebug() << resultText;
    ui->text_recognition_output->setText(resultText);
    reply->deleteLater(); // ȷ���ظ������ڴ�������ɾ��
}
