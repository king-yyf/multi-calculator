#include "sdf_mainwindow.h"
#include "ui_sdf_mainwindow.h"
#include <QtWidgets>

SDF_MainWindow::SDF_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SDF_MainWindow)
{
    ui->setupUi(this);
    state=state1;
    floatNum=6;
    QRegExp regx("[A-Z_]+[A-Za-z_0-9]*");
    QValidator *validator = new QRegExpValidator(regx, ui->name );
    ui->name->setValidator(validator);
}

SDF_MainWindow::~SDF_MainWindow()
{
    delete ui;
}

void SDF_MainWindow::Output(int state, double n){
    switch(state)
    {
    case state1:
        ui->expre->setText(QString::number(n,'f',floatNum));
        break;
    case state2:
        ui->expre->setText(QString::number(n,'e',floatNum));
        break;
    case state3:
        ui->expre->setText(QString::number(n,'g',floatNum));
        break;
    }
}

void SDF_MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1==Qt::Checked)
        expression.isRad=false;
    else
        expression.isRad=true;
    QString t=ui->expre->text();
    bool ok;
    double tn=t.toDouble(&ok);
    if(ok)
    {
        switch(expression.isRad)
        {
        case true:
            Output(state,tn/180*PAI);
            break;
        case false:
            Output(state,tn/PAI*180);
            break;
        }
    }
}

void SDF_MainWindow::on_floatNum_valueChanged(int arg1)
{
    floatNum=arg1;
}

void SDF_MainWindow::on_help_clicked()
{
    QMessageBox::information(this,"帮助","1):表达式的输入格式参见高级模式帮助内容(可带变量)，\n"
                                       "2):变量名由字母数字或下划线构成，由大写字母或下划线开头，\n"
                                       "3):格式控制选项与高级模式格式控制用法类似，\n"
                                       "4):当添加变量和已有变量名称相同时，相当于对原变量重新赋值，\n"
                             );
}

void SDF_MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    if(arg1==Qt::Checked)
        state=state2;
    else if(arg1==Qt::Unchecked)
        state=state1;
    else
        state=state3;
    QString t=ui->expre->text();
    bool ok;
    double tn=t.toDouble(&ok);
    if(ok)
    {
        Output(state,tn);
    }
}

void SDF_MainWindow::on_cal_clicked()
{
    QString tem=ui->expre->text();
    QString t=varDao.trans(tem);
    expression.SetExpression(t);
    if(expression.LegalAndCal())
    {
        double tresult=expression.GetResult();
        if(tresult!=tresult||tresult+1==tresult)
            ui->expre->setText("表达式错误或数值溢出！");
        else
            Output(state,expression.GetResult());    //::
    }
    else
    {
       ui->expre->setText("表达式错误或数值溢出！");
    }
}

void SDF_MainWindow::on_pushButton_clicked()    //添加变量
{
    QString t=ui->name->text();
    QString Qs=ui->value->text();
    ui->name->setText("");
    ui->value->setText("");
    bool ok;
    double tn=Qs.toDouble(&ok);
    if(!t.isEmpty()&&ok){
        int i=varDao.findByName(t);
        if(i>=0){
            varDao.modifyVar(i,tn);
        }else{
            Variable tem;
            tem.setName(t);
            tem.setValue(tn);
            varDao.addVar(tem);
        }
        ui->plainTextEdit->clear();
        ui->plainTextEdit->appendPlainText(varDao.displayVar());
    }
}

void SDF_MainWindow::on_error_clicked()     //清除上一个变量
{
   varDao.delVar();
   ui->plainTextEdit->clear();
   ui->plainTextEdit->appendPlainText(varDao.displayVar());
}

void SDF_MainWindow::on_clear_clicked()
{
    varDao.clearVar();
    ui->plainTextEdit->clear();
}
