#ifndef COIN_H
#define COIN_H

#include <QPushButton>

class coin : public QPushButton
{
    Q_OBJECT
public:
    explicit coin(QString butImg);
    int posX; //x坐标
    int posY; //y坐标
    bool flag; //正反标志
    void changeFlag();//改变标志,执行翻转效果
    QTimer *timer1; //正面翻反面 定时器
    QTimer *timer2; //反面翻正面 定时器
    int min = 1; //最小图片
    int max = 8; //最大图片

private:
    void flipAction(bool flag);
    bool isAnimation  = false; //做翻转动画的标志

protected:
    void mousePressEvent(QMouseEvent *e)
    {
        if(this->isAnimation )
        {
            return;
        }
        else
        {
            return QPushButton::mousePressEvent(e);
        }
    }

signals:
};

#endif // COIN_H
