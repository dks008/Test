#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <QGridLayout>

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(int index);
    int levelIndex;
    int gameArray[4][4];


private:
    void paintEvent(QPaintEvent *event);
    void playBoard();
    void backButton();

signals:
    void backToChooseLevel();
};

#endif // PLAYSCENE_H
