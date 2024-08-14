#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include "coin.h"
#include <QMainWindow>
#include <QGridLayout>

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(int index);
    void gameTips();
    int levelIndex;
    int gameArray[4][4];
    coin * coinBtn[4][4]; //金币按钮数组
    bool isWin = true;

private:
    void paintEvent(QPaintEvent *event);
    void playBoard();
    void backButton();

signals:
    void backToChooseLevel();
};

#endif // PLAYSCENE_H
