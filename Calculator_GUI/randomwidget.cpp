#include <QMessageBox>
#include <QCloseEvent>
#include "stdlib.h"
#include "time.h"
#include "randomwidget.h"
#include "ui_randomwidget.h"

RandomWidget::RandomWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RandomWidget)
{
    ui->setupUi(this);
    seed=(unsigned int)time(0);
    srand(seed);
    ui->intMaxLineEdit->setText(QString::number(RAND_MAX));
}

RandomWidget::~RandomWidget()
{
    delete ui;
}

void RandomWidget::on_intRandPushButton_clicked()
{
    /*if(ui->intMaxLineEdit->text()=="0"&&ui->intMinLineEdit->text()=="0")
        ui->intRandShowLineEdit->setText(QString::number(rand()));*/

        int max=ui->intMaxLineEdit->text().toInt();
        int min=ui->intMinLineEdit->text().toInt();
        ui->intRandShowLineEdit->setText(QString::number(rand()%(max-min)+min));

}

void RandomWidget::on_doubleRandPushButton_clicked()
{
    int max=ui->doubleMaxLineEdit->text().toInt();
    int min=ui->doubleMinLineEdit->text().toInt();
    ui->doubleRandShowLineEdit->setText(QString::number(rand()/(long double)RAND_MAX*(max-min)+min,'g',6));
}

void RandomWidget::on_HelpButton_clicked()
{
    QMessageBox::information(this,"帮助","整型随机数最大值与最小值之差不能超过默认最大值，\n"
                                       "浮点随机数无此限制。");
}

