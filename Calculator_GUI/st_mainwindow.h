#ifndef ST_MAINWINDOW_H
#define ST_MAINWINDOW_H

#include <QMainWindow>
#include "statistics.h"
#include<QApplication>
#include<QWidget>
#include<QtWidgets>

namespace Ui {
class ST_MainWindow;
}

class ST_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ST_MainWindow(QWidget *parent = 0);
    ~ST_MainWindow();

private slots:
    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ST_MainWindow *ui;
    statistics s;
};

#endif // ST_MAINWINDOW_H
