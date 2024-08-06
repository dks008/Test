#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include "playscene.h"
#include <QMainWindow>
#include <QGridLayout>

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    PlayScene *pScene = NULL;

private:
    void createLevelButtons(QGridLayout *layout);

signals:
    void backToMain();
};

#endif // CHOOSELEVELSCENE_H
