#ifndef EQUATIONMAINWINDOW_H
#define EQUATIONMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class EquationMainWindow;
}

class EquationMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EquationMainWindow(QWidget *parent = 0);
    ~EquationMainWindow();
private slots:
    void doSolve();
    void doHelp();
    void degreeClicked();


    void on_clearPushButton_clicked();

private:
    Ui::EquationMainWindow *ui;
    int degree;
};

#endif // EQUATIONMAINWINDOW_H
