/********************************************************************************
** Form generated from reading UI file 'mainscene.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCENE_H
#define UI_MAINSCENE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainScene
{
public:
    QAction *actionQuit;
    QWidget *centralwidget;
    QTextEdit *rulesText;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainScene)
    {
        if (MainScene->objectName().isEmpty())
            MainScene->setObjectName("MainScene");
        MainScene->resize(800, 600);
        actionQuit = new QAction(MainScene);
        actionQuit->setObjectName("actionQuit");
        centralwidget = new QWidget(MainScene);
        centralwidget->setObjectName("centralwidget");
        rulesText = new QTextEdit(centralwidget);
        rulesText->setObjectName("rulesText");
        rulesText->setGeometry(QRect(60, 200, 200, 150));
        rulesText->setStyleSheet(QString::fromUtf8("background-color: rgba(235, 175, 75, 80);\n"
" border:none"));
        MainScene->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainScene);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainScene->setMenuBar(menubar);
        statusbar = new QStatusBar(MainScene);
        statusbar->setObjectName("statusbar");
        MainScene->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionQuit);

        retranslateUi(MainScene);

        QMetaObject::connectSlotsByName(MainScene);
    } // setupUi

    void retranslateUi(QMainWindow *MainScene)
    {
        MainScene->setWindowTitle(QCoreApplication::translate("MainScene", "MainScene", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainScene", "\351\200\200\345\207\272", nullptr));
        rulesText->setHtml(QCoreApplication::translate("MainScene", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#000000;\">\346\270\270\346\210\217\350\247\204\345\210\231\357\274\232\345\260\206\346\211\200\346\234\211\347\241\254\345\270\201\347\277\273\345\210\260\346\255\243\351\235\242\357\274\210\351\207\221\350\211\262\357\274\211\345\215\263\344\270\272\346\270\270\346\210\217\350\203\234\345\210\251</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margi"
                        "n-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#000000;\">\346\270\270\346\210\217\347\216\251\346\263\225\357\274\232\347\202\271\345\207\273\347\241\254\345\270\201\345\217\257\344\273\245\347\277\273\350\275\254\346\234\254\350\272\253\345\217\212\345\205\266\345\221\250\345\233\264\345\233\233\344\270\252\346\226\271\345\220\221\357\274\210\344\270\212\343\200\201\344\270\213\343\200\201\345\267\246\343\200\201\345\217\263\357\274\211\344\270\212\347\232\204\347\241\254\345\270\201</span></p></body></html>", nullptr));
        menu->setTitle(QCoreApplication::translate("MainScene", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainScene: public Ui_MainScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCENE_H
