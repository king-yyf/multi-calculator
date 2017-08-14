#include "st_mainwindow.h"
#include "ui_st_mainwindow.h"

ST_MainWindow::ST_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ST_MainWindow)
{
    ui->setupUi(this);
}

ST_MainWindow::~ST_MainWindow()
{
    delete ui;
}

void ST_MainWindow::on_pushButton_12_clicked()
{
    QString t=ui->lineEdit_2->text();
    if(t=="0"){
        ui->lineEdit_2->setText("1");
    }else{
        ui->lineEdit_2->setText(t+"1");
    }
}

void ST_MainWindow::on_pushButton_13_clicked()
{
    QString t=ui->lineEdit_2->text();
    if(t=="0"){
        ui->lineEdit_2->setText("2");
    }else{
        ui->lineEdit_2->setText(t+"2");
    }
}

void ST_MainWindow::on_pushButton_14_clicked()
{
    QString t=ui->lineEdit_2->text();
    if(t=="0"){
        ui->lineEdit_2->setText("3");
    }else{
        ui->lineEdit_2->setText(t+"3");
    }
}

void ST_MainWindow::on_pushButton_8_clicked()
{
    QString t=ui->lineEdit_2->text();
    if(t=="0"){
        ui->lineEdit_2->setText("4");
    }else{
        ui->lineEdit_2->setText(t+"4");
    }
}

void ST_MainWindow::on_pushButton_9_clicked()
{
    QString t=ui->lineEdit_2->text();
    if(t=="0"){
        ui->lineEdit_2->setText("5");
    }else{
        ui->lineEdit_2->setText(t+"5");
    }
}

void ST_MainWindow::on_pushButton_10_clicked()
{
    QString t=ui->lineEdit_2->text();
    if(t=="0"){
        ui->lineEdit_2->setText("6");
    }else{
        ui->lineEdit_2->setText(t+"6");
    }
}

void ST_MainWindow::on_pushButton_4_clicked()
{
    QString t=ui->lineEdit_2->text();
    if(t=="0"){
        ui->lineEdit_2->setText("7");
    }else{
        ui->lineEdit_2->setText(t+"7");
    }
}

void ST_MainWindow::on_pushButton_5_clicked()
{
    QString t=ui->lineEdit_2->text();
    if(t=="0"){
        ui->lineEdit_2->setText("8");
    }else{
        ui->lineEdit_2->setText(t+"8");
    }
}

void ST_MainWindow::on_pushButton_6_clicked()
{
    QString t=ui->lineEdit_2->text();
    if(t=="0"){
        ui->lineEdit_2->setText("9");
    }else{
        ui->lineEdit_2->setText(t+"9");
    }
}

void ST_MainWindow::on_pushButton_15_clicked()
{
    QString t=ui->lineEdit_2->text();
    if(t=="0"){
        ui->lineEdit_2->setText("0");
    }else{
        ui->lineEdit_2->setText(t+"0");
    }
}

void ST_MainWindow::on_pushButton_7_clicked()
{
    QString t=ui->lineEdit_2->text();
    if(t=="0"){
        ui->lineEdit_2->setText("-");
    }
}

void ST_MainWindow::on_pushButton_11_clicked()
{
    QString t=ui->lineEdit_2->text();
    ui->lineEdit_2->setText(t+".");
}

void ST_MainWindow::on_pushButton_26_clicked()      //清除
{
    QString t=ui->lineEdit->text();
    if(t!="0"){
        s.Erase();
        ui->lineEdit->setText(s.renew());
    }
}

void ST_MainWindow::on_pushButton_18_clicked()  //和
{
    ui->lcdNumber->display(s.Sum());
}

void ST_MainWindow::on_pushButton_19_clicked()  //平方和
{
    ui->lcdNumber->display(s.DSum());
}

void ST_MainWindow::on_pushButton_20_clicked()   //标准差
{
    ui->lcdNumber->display(s.StaVar());
}

void ST_MainWindow::on_pushButton_21_clicked()    //无偏方差
{
    ui->lcdNumber->display(s.UnVariance());
}

void ST_MainWindow::on_pushButton_17_clicked()     //方差
{
    ui->lcdNumber->display(s.Variance());
}

void ST_MainWindow::on_pushButton_16_clicked()   //均值
{
    ui->lcdNumber->display(s.Average());
}

void ST_MainWindow::on_pushButton_22_clicked()   //中位数
{
    ui->lcdNumber->display(s.Midnum());
}

void ST_MainWindow::on_pushButton_23_clicked()
{
    ui->lcdNumber->display(s.Max_Min());
}

void ST_MainWindow::on_pushButton_24_clicked() //升序
{
    ui->lineEdit->setText(s.Sort());
}

void ST_MainWindow::on_pushButton_25_clicked() //降序
{
    ui->lineEdit->setText(s.rSort());
}

void ST_MainWindow::on_pushButton_clicked()  //添加
{
    QString t=ui->lineEdit_2->text();
    bool ok;
    double num=t.toDouble(&ok);
    if(ok){
        s.AddData(num);
        ui->lineEdit_2->setText("0");
        ui->lineEdit->setText(s.renew());
    }
}

void ST_MainWindow::on_pushButton_27_clicked()
{
    ui->lineEdit->setText("0");
    ui->lineEdit_2->setText("0");
    s.empty();
}

void ST_MainWindow::on_pushButton_2_clicked()                 //帮助
{
    QMessageBox::information(this,"帮助","1:按添加键将数据加入数据集，支持小数，负数\n"
                                       "2:清除用于删除上一个输入数据，清除全部用于清空数据\n"
                             );
}
