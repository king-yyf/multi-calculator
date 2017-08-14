#ifndef MAINWINDOWC_H
#define MAINWINDOWC_H


#include<QMainWindow>
#include<QtWidgets>

#include<QApplication>
#include<QWidget>
namespace Ui {
class MainWindowComplex;
}

class MainWindowComplex : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindowComplex(QWidget *parent = 0);
    ~MainWindowComplex();

private:
    Ui::MainWindowComplex *ui;
    QToolBar* mainToolBar;
    QAction* advancedMode;
    QAction* inputData;
    QAction* actHelp;


private slots:
    void on_Button1_clicked();

    void on_Button2_clicked();

    void on_Button3_clicked();

    void on_Button0_clicked();

    void on_Button4_clicked();

    void on_Button5_clicked();

    void on_Button6_clicked();

    void on_Button7_clicked();

    void on_Button8_clicked();

    void on_Button9_clicked();

    void on_Button_pos_clicked();

    void on_Button_neg_clicked();

    void on_Button_point_clicked();

    void on_Button_multi_clicked();

    void on_Button_div_clicked();

    void on_real_clicked();

    void on_virtual_2_clicked();

    void on_erase_answer_clicked();

    void on_erase_real_clicked();

    void on_erase_virtual_clicked();

    void on_ans_clicked();

    void doHelp();

    void on_Button0_2_clicked();
};

#endif // MAINWINDOWC_H
