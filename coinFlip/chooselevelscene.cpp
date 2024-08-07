#include "chooselevelscene.h"
#include "mypushbutton.h"
#include <QMenuBar>
#include <QPainter>
#include <QLabel>
#include <QGridLayout>
#include <QTimer>

ChooseLevelScene::ChooseLevelScene(QWidget *parent)
    : QMainWindow{parent}
{
    //设置窗口固定大小
    this->setFixedSize(320,588);
    //设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    //设置标题
    this->setWindowTitle("选择关卡");

    //创建菜单栏
    QMenuBar * bar = this->menuBar();
    this->setMenuBar(bar);
    //创建开始菜单
    QMenu * startMenu = bar->addMenu("开始");
    //创建按钮菜单项
    QAction * quitAction = startMenu->addAction("退出");
    //点击退出 退出游戏
    connect(quitAction,&QAction::triggered,[=](){this->close();});

    //创建网格，放置关卡按钮
    QGridLayout *chooseLevel = new QGridLayout();
    chooseLevel->setContentsMargins(0,120,0,50);
    QWidget *choose = new QWidget(this);
    //设置中心窗口，居中分布
    this->setCentralWidget(choose);
    choose->setLayout(chooseLevel);
    //创建关卡按钮
    createLevelButtons(chooseLevel);
    //创建返回按钮
    backButton();
}

void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //加载标题
    pix.load(":/res/Title.png");
    painter.drawPixmap( (this->width() - pix.width())*0.5,30,pix.width(),pix.height(),pix);
}

void ChooseLevelScene::createLevelButtons(QGridLayout *layout) {
    for (int i = 0; i < 20; i++) {
        MyPushButton *menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this); // 设置父级为当前窗口
        layout->addWidget(menuBtn, i / 4, i % 4);

        // 按钮上显示的文字
        QLabel *label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(), menuBtn->height());
        label->setText(QString::number(i + 1));
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter); // 设置居中
        layout->addWidget(label, i / 4, i % 4);
        label->setAttribute(Qt::WA_TransparentForMouseEvents, true); // 鼠标事件穿透

        // 监听选择关卡按钮的信号槽
        connect(menuBtn, &MyPushButton::clicked, [=]() {
            if (pScene == nullptr) { // 游戏场景最好不用复用，直接移除掉创建新的场景
                this->hide();
                pScene = new PlayScene(i + 1); // 将选择的关卡号传入给PlayerScene
                pScene->show();
                connect(pScene,&PlayScene::backToChooseLevel,this,[=](){
                    QTimer::singleShot(200,this,[=](){
                        this->show();
                        delete pScene;
                        pScene = NULL;
                    });
                });
            }
        });
    }
}

void ChooseLevelScene::backButton(){
    //返回按钮
    MyPushButton * closeBtn = new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    closeBtn->setParent(this);
    closeBtn->move(this->width()-closeBtn->width(),this->height()-closeBtn->height());
    closeBtn->show();
    connect(closeBtn,&MyPushButton::clicked,this,&ChooseLevelScene::backToMain);
}
