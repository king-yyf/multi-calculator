#include <QtWidgets>
#include <complex>
#include "equationmainwindow.h"
#include "ui_equationmainwindow.h"
using std::complex;
void solve1equations(double a, double b, double &x);
void solve2equations(double a,double b,double c,
                     complex<double> &x1,complex<double> &x2);
void solve3equations(double a, double b, double c, double d,
                    complex<double> &x1, complex<double> &x2, complex<double> &x3);
EquationMainWindow::EquationMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EquationMainWindow),degree(1)
{

    ui->setupUi(this);
    setWindowTitle("解方程");
    setFixedSize(300,180);
    QToolBar* mainToolBar=new QToolBar;
    QAction* help=mainToolBar->addAction("帮助",this,SLOT(doHelp()));
    addToolBar(mainToolBar);
    mainToolBar->setMovable(false);
    ui->radioButton_1->setChecked(true);
    ui->radioButton_2->setChecked(false);
    ui->radioButton_3->setChecked(false);

    connect(ui->solvePushButton,SIGNAL(clicked()),this,SLOT(doSolve()));
    connect(ui->radioButton_1,SIGNAL(clicked()),this,SLOT(degreeClicked()));
    connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(degreeClicked()));
    connect(ui->radioButton_3,SIGNAL(clicked()),this,SLOT(degreeClicked()));
}

EquationMainWindow::~EquationMainWindow()
{
    delete ui;
}

void EquationMainWindow::doSolve()
{
    bool ab,bb,cb,db;
    switch(degree)
    {
    case 1:
    {
        int a=ui->lineEdit_1->text().toDouble(&ab);
        int b=ui->lineEdit_2->text().toDouble(&bb);
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        if(ab==false||bb==false)
        {
            QMessageBox::information(this,"错误","请输入正确的a,b");
            return;
        }
        double x;
        solve1equations(a,b,x);
        ui->lineEdit_x1->setText(QString::number(x));
        ui->lineEdit_x2->clear();
        ui->lineEdit_x3->clear();
        break;
    }
    case 2:
    {
        int a=ui->lineEdit_1->text().toDouble(&ab);
        int b=ui->lineEdit_2->text().toDouble(&bb);
        int c=ui->lineEdit_3->text().toDouble(&cb);
        ui->lineEdit_4->clear();
        if(ab==false||bb==false||cb==false)
        {
            QMessageBox::information(this,"错误","请输入正确的a,b,c");
            return;
        }
        complex<double> x1,x2;
        solve2equations(a,b,c,x1,x2);
        ui->lineEdit_x1->setText(QString::number(x1.real())+" + "+QString::number(x1.imag())+'i');
        ui->lineEdit_x2->setText(QString::number(x2.real())+" + "+QString::number(x2.imag())+'i');
        ui->lineEdit_x3->clear();
        break;
    }
    case 3:
    {
        int a=ui->lineEdit_1->text().toDouble(&ab);
        int b=ui->lineEdit_2->text().toDouble(&bb);
        int c=ui->lineEdit_3->text().toDouble(&cb);
        int d=ui->lineEdit_4->text().toDouble(&db);
        if(ab==false||bb==false||cb==false||db==false)
        {
            QMessageBox::information(this,"错误","请输入正确的a,b,c,d");
            return;
        }
        complex<double> x1,x2,x3;
        solve3equations(a,b,c,d,x1,x2,x3);
        ui->lineEdit_x1->setText(QString::number(x1.real())+" + "+QString::number(x1.imag())+'i');
        ui->lineEdit_x2->setText(QString::number(x2.real())+" + "+QString::number(x2.imag())+'i');
        ui->lineEdit_x3->setText(QString::number(x3.real())+" + "+QString::number(x3.imag())+'i');
        break;
    }
    }
}

void EquationMainWindow::doHelp()
{
    QMessageBox::information(this,"帮助","方程形式：\n"
                                       "一元一次方程：ax+b=0\n"
                                       "一元二次方程：ax^2+bx+c=0\n"
                                       "一元三次方程：ax^3+bx^2+cx+d=0");
}

void EquationMainWindow::degreeClicked()
{
    if(ui->radioButton_1->isChecked())
    {
        degree=1;
    }
    else if(ui->radioButton_2->isChecked())
    {
        degree=2;
    }
    else
    {
        degree=3;
    }
}
void solve1equations(double a,double b,double& x)
{
    x=(-1)*b/a;
}
void solve2equations(double a,double b,double c,
                     complex<double> &x1,complex<double> &x2)
{
    complex<double> delta=b*b-4*a*c;
    x1=((-1)*b+sqrt(delta))/2.0*a;
    x2=((-1)*b-sqrt(delta))/2.0*a;
}

void solve3equations(double a,double b,double c,double d,
                    complex<double> &x1,complex<double> &x2,complex<double> &x3)
{
    double t1=36*a*b*c-8*b*b*b-108*a*a*d;
    double t2=12*a*c-4*b*b;
    double delta=t1*t1+t2*t2*t2;
    complex<double> t3,t4;
    if(delta>0)
    {
        double temp1=t1+sqrt(delta);
        double temp2=t1-sqrt(delta);
        if(temp1<0)
        {
            t3=-pow(-temp1,1.0/3.0);
        }
        else
        {
            t3=pow(temp1,1.0/3.0);
        }
        if(temp2<0)
        {
            t4=-pow(-temp2,1.0/3.0);
        }
        else
        {
            t4=pow(temp2,1.0/3.0);
        }

    }
    else
    {
        t3=pow(t1+sqrt((complex<double>)delta),1.0/3.0);
        t4=pow(t1-sqrt((complex<double>)delta),1.0/3.0);
    }
    x1=((-2)*b+t3+t4)/(6.0*a);
    complex<double> ti1(-1,sqrt(3));
    complex<double> ti2(-1,-sqrt(3));
    x2=(-1)*b/3.0*a+ti1*t3/12.0*a+ti2*t4/12.0*a;
    x3=(-1)*b/3.0*a+ti2*t3/12.0*a+ti1*t4/12.0*a;
}


void EquationMainWindow::on_clearPushButton_clicked()
{
    ui->lineEdit_1->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_x1->setText("");
    ui->lineEdit_x2->setText("");
    ui->lineEdit_x3->setText("");
}
