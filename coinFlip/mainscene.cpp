#include "mainscene.h"
#include "./ui_mainscene.h"
#include "mypushbutton.h"
#include "chooselevelscene.h"
#include <QUrl>
#include <QTextEdit>
#include <QPainter>
#include <QTimer>
#include <QSoundEffect>
#include <QRandomGenerator>

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    this -> setFixedSize(320,588);//设置窗体大小
    this -> setWindowIcon(QPixmap(":/res/Coin0001.png"));//设置应用图片标识
    this -> setWindowTitle("翻翻翻翻金币！");
    connect(ui -> actionQuit,&QAction::triggered,[=](){this -> close();});

    //开始按钮
    MyPushButton * startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    //放置在合适位置
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.7);
    startBtn->show();

    //设置音效
    QSoundEffect *startSound= new QSoundEffect;
    startSound->setSource(QUrl(":/res/TapButtonSound.wav"));
    startSound->setVolume(1);

    //选择关卡页面
    ChooseLevelScene *chooseScene = new ChooseLevelScene;

    //开始，进入关卡选择界面
    connect(startBtn,&MyPushButton::clicked,[=](){
        startSound->play();
        startBtn->zoom1(); //向下跳跃
        startBtn->zoom2(); //向上跳跃
        QTimer::singleShot(300, this,[=](){
            this->hide();
            chooseScene->setGeometry(this->geometry());
            chooseScene->show();
        });
    });

    //返回开始界面
    connect(chooseScene,&ChooseLevelScene::backToMain,this,[=](){
        QTimer::singleShot(200,this,[=](){
            this->setGeometry(chooseScene->geometry());
            this->show();
            chooseScene->hide();
        });
    });

    //返回按钮
    MyPushButton * closeBtn = new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    closeBtn->setParent(this);
    closeBtn->move(this->width()-closeBtn->width(),this->height()-closeBtn->height());
    closeBtn->show();
    connect(closeBtn,&MyPushButton::clicked,this,[=](){
        closeBtn->move(QRandomGenerator::global()->bounded(10, 240),QRandomGenerator::global()->bounded(15, 570));
    });

    //游戏提示
    ui->rulesText->hide();
    MyPushButton *rulesBtn = new MyPushButton(":/res/rules.png");
    rulesBtn->setParent(this);
    rulesBtn->setGeometry(280,40,25,37);
    rulesBtn->show();
    connect(rulesBtn,&MyPushButton::clicked,this,[=](){
        if(ui->rulesText->isVisible()){
            ui->rulesText->hide();
        }
        else {
            ui->rulesText->show();
        }
    });
}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::paintEvent(QPaintEvent*)
{
    //指定绘图设备
    QPainter painter(this);
    QPixmap pix;
    //加载图片
    pix.load(":/res/PlayLevelSceneBg.png");
    //绘制背景
    painter.drawPixmap(0,0,this -> width(),this -> height(),pix);

    //加载标题图片
    pix.load(":/res/Title.png");
    //缩放
    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
    //绘制背景
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);
}
