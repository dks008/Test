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

signals:
};

#endif // COIN_H
