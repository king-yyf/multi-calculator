
#ifndef NUMAINWINDOW_H
#define NUMAINWINDOW_H

#include <QMainWindow>
#include<QApplication>
#include<QWidget>
#include<QtWidgets>
namespace Ui {
class NUMainWindow;
}

class NUMainWindow : public QMainWindow
{

    Q_OBJECT

public:
    explicit NUMainWindow(QWidget *parent = 0);
    ~NUMainWindow();

private:
    Ui::NUMainWindow *ui;
    QToolBar* mainToolBar;
    QAction* advancedMode;
    QAction* inputData;
    QAction* actHelp;


private slots:
   // void doAdvancedMode();
    void doHelp();
    void on_button1_clicked();
    void on_button2_clicked();
    void on_button3_clicked();
    void on_button0_clicked();
    void on_button4_clicked();
    void on_button5_clicked();
    void on_button6_clicked();
    void on_button7_clicked();
    void on_button8_clicked();
    void on_button9_clicked();
    void on_button_erase_clicked();
    void on_button_tenTwo_clicked();
    void on_button_tenEight_clicked();
    void on_button_tenSixteen_clicked();
    void on_button_twoTen_clicked();
    void on_button_twoEight_clicked();
    void on_button_twoSixteen_clicked();


    //void on_button_clicked();
    void on_button_eightTwo_clicked();
    void on_button_eightTen_clicked();
    void on_button_eightSixteen_clicked();
};


#endif // NUMAINWINDOW_H
