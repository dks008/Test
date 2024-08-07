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
    PlayScene *pScene = NULL;

private:
    void paintEvent(QPaintEvent *event);
    void createLevelButtons(QGridLayout *layout);
    void backButton();

signals:
    void backToMain();
};

#endif // CHOOSELEVELSCENE_H
