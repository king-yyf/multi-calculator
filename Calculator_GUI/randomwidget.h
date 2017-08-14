#ifndef RANDOMWIDGET_H
#define RANDOMWIDGET_H

#include <QWidget>


namespace Ui {
class RandomWidget;
}

class RandomWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RandomWidget(QWidget *parent = 0);
    ~RandomWidget();

private slots:
    void on_intRandPushButton_clicked();

    void on_doubleRandPushButton_clicked();

    void on_HelpButton_clicked();

private:
    Ui::RandomWidget *ui;
    unsigned int seed;
};

#endif // RANDOMWIDGET_H
