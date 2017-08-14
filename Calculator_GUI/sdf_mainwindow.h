#ifndef SDF_MAINWINDOW_H
#define SDF_MAINWINDOW_H

#include <QMainWindow>
#include "expression.h"
#include "variable.h"
namespace Ui {
class SDF_MainWindow;
}
enum format{
    state1=1,
    state2=2,
    state3=3
};

class SDF_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SDF_MainWindow(QWidget *parent = 0);
    ~SDF_MainWindow();

    void Output(int state,double n);
  //  void Display();
private slots:
    void on_checkBox_stateChanged(int arg1);

    void on_floatNum_valueChanged(int arg1);

    void on_help_clicked();

    void on_checkBox_2_stateChanged(int arg1);

    void on_cal_clicked();

    void on_pushButton_clicked();

    void on_error_clicked();

    void on_clear_clicked();

private:
    Ui::SDF_MainWindow *ui;
    Expression expression;
    VariableDao varDao;
    format state;
    int floatNum;
};

#endif // SDF_MAINWINDOW_H
