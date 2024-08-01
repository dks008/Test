#include "mypushbutton.h"
#include <QPixmap>
#include <QDebug>
#include <QPropertyAnimation>

MyPushButton::MyPushButton(QWidget *parent)
    : QPushButton(parent) {
    // 默认构造函数的实现
}

MyPushButton::MyPushButton(QString normalImg, QString pressImg, QWidget *parent)
    : QPushButton(parent), normalImgPath(normalImg), pressedImgPath(pressImg) {
    // 创建 QPixmap 对象
    QPixmap pixmap;

    // 判断是否能够加载正常显示的图片，若不能提示加载失败
    bool ret = pixmap.load(normalImgPath);
    if (!ret) {
        qDebug() << normalImg << "加载图片失败!";
    }

    // 设置图片的固定尺寸
    this->setFixedSize(pixmap.width(), pixmap.height());

    // 设置不规则图片的样式表
    this->setStyleSheet("QPushButton{border:0px;}");

    // 设置图标
    this->setIcon(pixmap);

    // 设置图标大小
    this->setIconSize(QSize(pixmap.width(), pixmap.height()));
}

void MyPushButton::zoom1()
{
    //创建动画对象
    QPropertyAnimation * animation1 = new QPropertyAnimation(this,"geometry");
    //设置时间间隔，单位毫秒
    animation1->setDuration(200);
    //创建起始位置
    animation1->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //创建结束位置
    animation1->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //设置缓和曲线，QEasingCurve::OutBounce 为弹跳效果    animation1->setEasingCurve(QEasingCurve::OutBounce);
    //开始执行动画
    animation1->start();
}

void MyPushButton::zoom2()
{
    QPropertyAnimation * animation1 =  new QPropertyAnimation(this,"geometry");
    animation1->setDuration(200);
    animation1->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation1->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    animation1->start();
}
