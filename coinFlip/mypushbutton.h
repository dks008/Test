#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = nullptr);
    MyPushButton(QString normalImg, QString pressImg = "", QWidget *parent = nullptr);
    void zoom1();
    void zoom2();

    QString normalImgPath;  // 默认显示图片路径
    QString pressedImgPath; // 按下后显示图片路径

signals:
};

#endif // MYPUSHBUTTON_H
