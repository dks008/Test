#include "mainscene.h"
#include "./ui_mainscene.h"
#include "mypushbutton.h"
#include <QPainter>

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
    QPainter painter(this);//指定绘图设备
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");//加载图片
    painter.drawPixmap(0,0,this -> width(),this -> height(),pix);//绘制背景

    pix.load(":/res/Title.png");//加载标题图片
    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);//缩放
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);//绘制背景

    MyPushButton * startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.7);
    startBtn->show();
    connect(startBtn,&MyPushButton::clicked,[=](){
        startBtn->zoom1(); //向下跳跃
        startBtn->zoom2(); //向上跳跃

    });
}
