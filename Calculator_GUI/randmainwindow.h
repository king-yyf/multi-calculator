#ifndef RANDMAINWINDOW
#define RANDMAINWINDOW
#include<QMainWindow>
#include"randomwidget.h"
class RandMainwindow:public QMainWindow
{
    Q_OBJECT

public:
    RandMainwindow(QWidget* parent=0):QMainWindow(parent)
    {
        RandomWidget* randwidget=new RandomWidget;
        setCentralWidget(randwidget);
        setFixedSize(370,215);
        setWindowTitle("随机数");
    }
};

#endif // RANDMAINWINDOW

