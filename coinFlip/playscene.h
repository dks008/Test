#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(int index);
    void paintEvent(QPaintEvent *event);
    int levelIndex;

signals:
    void backToChooseLevel();
};

#endif // PLAYSCENE_H
