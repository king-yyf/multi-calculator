#ifndef FRACTIN_H
#define FRACTIN_H

#include <QMainWindow>
#include<QApplication>
#include<QWidget>
#include<QtWidgets>
#include<QString>

namespace Ui {
class fractin;
}

class fractin : public QMainWindow
{
    Q_OBJECT

public:
    explicit fractin(QWidget *parent = 0);//
    ~fractin();

private:
    Ui::fractin *ui;
    QToolBar* mainToolBar;
    QString text;
    QAction* actHelp;
    //QString error;

private slots:
    void doHelp();
    void on_pushButton0_clicked();
    void on_pushButton1_clicked();
    void on_pushButton2_clicked();
    void on_pushButton3_clicked();
    void on_pushButton4_clicked();
    void on_pushButton5_clicked();
    void on_pushButton6_clicked();
    void on_pushButton7_clicked();
    void on_pushButton8_clicked();
    void on_pushButton9_clicked();
    void on_cancel_clicked();
    void on_divide_clicked();
    void on_plus_clicked();
    void on_mutiply_clicked();
    void on_subtract_clicked();
    void on_fraction_line_clicked();
    void on_left_bracket_clicked();
    void on_right_bracket_clicked();
    void on_empty_clicked();
    void on_equal_clicked();
    void on_point_clicked();
    void on_simplify_clicked();
    void on_switchButton_clicked();




};

#endif // FRACTIN_H


/*
private:
    Ui::STMainWindow *ui;
    QToolBar* mainToolBar;
    //QAction* advancedMode;
    //QAction* inputData;
    QAction* actAbout;
    QAction* actHelp;
*/
