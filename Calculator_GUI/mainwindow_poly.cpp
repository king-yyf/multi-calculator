#include "mainwindow_poly.h"
#include "ui_mainwindow_poly.h"
#include "poly.h"

MainWindowPoly::MainWindowPoly(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowPoly)
{
    ui->setupUi(this);
    mainToolBar=new QToolBar(this);
    mainToolBar->setAllowedAreas(Qt::TopToolBarArea);
    mainToolBar->setMovable(false);
    actHelp=mainToolBar->addAction("帮助",this,SLOT(doHelp()));
    setWindowTitle("多项式功能");
    addToolBar(mainToolBar);
    setFixedSize(399,290);
}


void MainWindowPoly::doHelp()
{
    QMessageBox::information(this,"帮助","输入格式：\n1.先输入一个数，然后点击系数或次数按钮;\n"
                                       "2.系数和次数均为浮点数 \n"
                                       "3.系数次数允许是负数\n"
                                       "示例："
                                       "2->系数按钮->6->次数按钮->结果=按钮->2x^6"
                                       "\n注意事项:\n1. 清除结果按钮将本次结果全部清空，重新开始下一次操作");
}


MainWindowPoly::~MainWindowPoly()
{
    delete ui;
}
QString ptem="";
QString tempcoef;
QString tempexp;

void MainWindowPoly::on_button1_clicked()
{
    ptem=ptem.append('1');
}

void MainWindowPoly::on_button2_clicked()
{
    ptem=ptem.append('2');
}

void MainWindowPoly::on_button3_clicked()
{
    ptem=ptem.append('3');
}

void MainWindowPoly::on_button0_clicked()
{
    ptem=ptem.append('0');
}


void MainWindowPoly::on_button4_clicked()
{
    ptem=ptem.append('4');
}

void MainWindowPoly::on_button5_clicked()
{
    ptem=ptem.append('5');
}

void MainWindowPoly::on_button6_clicked()
{
    ptem=ptem.append('6');
}

void MainWindowPoly::on_button8_clicked()
{
    ptem=ptem.append('8');
}
void MainWindowPoly::on_button9_clicked()
{
    ptem=ptem.append('9');
}

void MainWindowPoly::on_button7_clicked()
{
    ptem=ptem.append('7');
}

void MainWindowPoly::on_button_pos_clicked()
{
    ptem=ptem.append('.');
}

void MainWindowPoly::on_button_erasecoef_clicked()
{
    ptem="";
    tempcoef="";
    tempcoef=tempcoef.append('0');
    ui->inputcoef->setText(ptem);  //将页面清空
}

void MainWindowPoly::on_button_eraseexp_clicked()
{
    ptem="";
    tempexp="";
    tempexp=tempexp.append('0');
    ui->inputexp->setText(ptem);   //将页面清空
}

void MainWindowPoly::on_button_answer_clicked()  //输出结果
{

    QString display;
    double numcoef=tempcoef.toDouble();    //按空格之前 先将数字保存好
    double numexp=tempexp.toDouble();
    if(numcoef!=0)
    {
    Poly * pt= new Poly(numcoef,numexp);
    pt->AddPoly();               //向多项式中增加项
    }
    ptem="";                        //将temp更新为空
    display=Poly::toString();
    ui->answer->setText(display);   //显示一个字符串
}

void MainWindowPoly::on_button_coef_clicked()
{
    tempcoef=ptem;
    ui->inputcoef->setText(ptem);
    ptem="";
}

void MainWindowPoly::on_button_exp_clicked()
{
    tempexp=ptem;
    ui->inputexp->setText(ptem);
    ptem="";
}


void MainWindowPoly::on_button_neg_clicked()
{

     if(ptem.isEmpty()){
          ptem=ptem.append('-');
        }
}

void MainWindowPoly::on_button_Diff_clicked()
{
    QString display;
    display=Poly::Diff();
    ui->answer->setText(display);
}



void MainWindowPoly::on_button_erasecoef_2_clicked()
{
    tempcoef="";
    tempexp="";
    ui->inputexp->setText("");
    ui->inputcoef->setText("");
    ui->answer->setText("");
    (Poly::head)->next=NULL;              //重新开始
}

void MainWindowPoly::on_pushButton_clicked() //恢复求导之前的状态
{
    QString display;
    display=Poly::toString();
    ui->answer->setText(display);
}

