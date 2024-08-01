#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDebug>
#include <string>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_text_recognition_button_clicked();
    void handleAccessTokenReply(QNetworkReply* reply);
    void handleOCRResponse(QNetworkReply* reply);
    void onReplyFinished(QNetworkReply* reply);

private:
    void getAccessToken(const QString& imagePath);
    void sendOCRRequest(const QString& imagePath, const QString& accessToken);

    Ui::MainWindow* ui;
    QNetworkAccessManager* networkManager;
    QString accessToken;
    int expiresIn;
    QString imagePath;
    QNetworkAccessManager *nam;
};

#endif // MAINWINDOW_H
