#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QApplication>
#include<QWidget>
#include<QMainWindow>
#include<QtWidgets>
#include"calwidget.h"
#include"advanced_mainwindow.h"

class Mainwindow:public QMainWindow
{
    Q_OBJECT
public:
    explicit Mainwindow(QWidget *parent = 0);
    ~Mainwindow();
    QLineEdit* formatEdit;
private:
    QToolBar* mainToolBar;
    //QStatusBar* statusBar;
    //QCheckBox* formatCheckBox;
    //QPushButton* formatButton;
    QAction* advancedMode;
    //QAction* inputExpressionMannual;
    QAction* actAbout;
    QAction* actHelp;
    CalWidget* cal;
    AdvancedMainwindow* acal;
private slots:
    void doAdvancedMode();
    void doHelp();
    void doAbout();


};

#endif // MAINWINDOW_H

