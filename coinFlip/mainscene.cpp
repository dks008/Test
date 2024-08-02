#include "mainscene.h"
#include "./ui_mainscene.h"
#include "mypushbutton.h"
#include "chooselevelscene.h"
#include <QPainter>
#include <QTimer>

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    this -> setFixedSize(320,588);//设置窗体大小
    this -> setWindowIcon(QPixmap(":/res/Coin0001.png"));//设置应用图片标识
    this -> setWindowTitle("翻翻翻翻金币");
    connect(ui -> actionQuit,&QAction::triggered,[=](){this -> close();});
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

    //开始按钮
    MyPushButton * startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    //放置在合适位置
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.7);
    startBtn->show();

    //选择关卡页面
    ChooseLevelScene *chooseScene = new ChooseLevelScene;

    connect(startBtn,&MyPushButton::clicked,[=](){
        startBtn->zoom1(); //向下跳跃
        startBtn->zoom2(); //向上跳跃
        QTimer::singleShot(500, this,[=](){
            this->hide();
            chooseScene->show();
        });
    });

}
