#include "playscene.h"
#include "mypushbutton.h"
#include "coin.h"
#include "dataconfig.h"
#include <QMenuBar>
#include <QPainter>
#include <QLabel>
#include <QGridLayout>
#include <QTimer>

PlayScene::PlayScene(int index)
{
    //qDebug() << "当前关卡为"<< index;
    this->levelIndex = index;
    //设置窗口固定大小
    this->setFixedSize(320,588);
    //设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    //设置标题
    this->setWindowTitle("开始翻金币！");

    //创建菜单栏
    QMenuBar * bar = this->menuBar();
    this->setMenuBar(bar);
    //创建开始菜单
    QMenu * startMenu = bar->addMenu("开始");
    //创建按钮菜单项
    QAction * quitAction = startMenu->addAction("退出");
    //点击退出 退出游戏
    connect(quitAction,&QAction::triggered,[=](){this->close();});
    //创建返回按钮
    backButton();
    //创建游戏
    playBoard();

}

void PlayScene::paintEvent(QPaintEvent *)
{
    //加载背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //加载标题
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap( 10,30,pix.width(),pix.height(),pix);

    //当前关卡标题
    QLabel * label = new QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    label->setFont(font);
    QString str = QString("Leavel: %1").arg(this->levelIndex);
    label->setText(str);
    label->setGeometry(QRect(20, this->height() - 50,120, 50)); //设置大小和位置
    label->show();
}

void PlayScene::backButton(){
    //返回按钮
    MyPushButton * closeBtn = new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    closeBtn->setParent(this);
    closeBtn->move(this->width()-closeBtn->width(),this->height()-closeBtn->height());
    closeBtn->show();
    connect(closeBtn,&MyPushButton::clicked,this,&PlayScene::backToChooseLevel);
}

void PlayScene::playBoard(){
    //创建金币的背景图片
    for(int i = 0 ; i < 4;i++)
    {
        for(int j = 0 ; j < 4; j++)
        {
            //绘制背景图片
            QLabel* label = new QLabel;
            label->setFixedSize(50,50);
            label->setPixmap(QPixmap(":/res/BoardNode.png"));
            label->setParent(this);
            label->move(57 + i*50,200+j*50);

            //初始化二维数组
            dataConfig config;
            gameArray[i][j] = config.mData[this->levelIndex][i][j];

            //金币对象
            QString img;
            if(gameArray[i][j] == 1)
            {
                img = ":/res/Coin0001.png";
            }
            else
            {
                img = ":/res/Coin0008.png";
            }
            coin * Coin = new coin(img);
            Coin->setParent(this);
            Coin->move(59 + i*50,204+j*50);
            Coin->posX = i; //记录x坐标
            Coin->posY = j; //记录y坐标
            Coin->flag =gameArray[i][j]; //记录正反标志
            coinBtn[i][j] = Coin;

            connect(Coin,&coin::clicked,[=](){
                Coin->changeFlag();
                gameArray[i][j] = gameArray[i][j] == 0 ? 1 : 0; //数组内部记录的标志同步修改

                //翻转周围硬币
                QTimer::singleShot(150, this,[=]()
                {
                    if(Coin->posX+1 <=3)
                    {
                        coinBtn[Coin->posX+1][Coin->posY]->changeFlag();
                        gameArray[Coin->posX+1][Coin->posY] = gameArray[Coin->posX+1][Coin->posY]== 0 ? 1 : 0;
                    }
                    if(Coin->posX-1>=0)
                    {
                        coinBtn[Coin->posX-1][Coin->posY]->changeFlag();
                        gameArray[Coin->posX-1][Coin->posY] = gameArray[Coin->posX-1][Coin->posY]== 0 ? 1 : 0;
                    }
                    if(Coin->posY+1<=3)
                    {
                        coinBtn[Coin->posX][Coin->posY+1]->changeFlag();
                        gameArray[Coin->posX][Coin->posY+1] = gameArray[Coin->posX+1][Coin->posY]== 0 ? 1 : 0;
                    }
                    if(Coin->posY-1>=0)
                    {
                        coinBtn[Coin->posX][Coin->posY-1]->changeFlag();
                        gameArray[Coin->posX][Coin->posY-1] = gameArray[Coin->posX+1][Coin->posY]== 0 ? 1 : 0;
                    }
                });

                //判断游戏胜利条件
                this->isWin = true;
                for(int i = 0 ; i < 4;i++)
                {
                    for(int j = 0 ; j < 4; j++)
                    {
                        //qDebug() << coinBtn[i][j]->flag ;
                        if( coinBtn[i][j]->flag == false)
                        {
                            this->isWin = false;
                            break;
                        }
                    }
                }

                if(this->isWin)
                {
                    qDebug() << "胜利";
                }
            });
        }
    }
}
