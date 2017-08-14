#include "mainwindow_complex.h"
#include "ui_mainwindow_complex.h"
#include "complex.h"

MainWindowComplex::MainWindowComplex(QWidget *parent) :// 基类构造函数
    QMainWindow(parent),
    ui(new Ui::MainWindowComplex)
{
    ui->setupUi(this);mainToolBar=new QToolBar(this);
    mainToolBar->setAllowedAreas(Qt::TopToolBarArea);
    mainToolBar->setMovable(false);
    actHelp=mainToolBar->addAction("帮助",this,SLOT(doHelp()));
    setWindowTitle("复数运算");
    addToolBar(mainToolBar);
    setFixedSize(420,267);


}

void MainWindowComplex::doHelp()
{
    QMessageBox::information(this,"帮助","功能：\n实部和虚部均为double类型的加 减 乘 除 求模运算;\n"
                                        "输入格式：\n"
                                        "示例:\n2-> '实部'按钮->6->'虚部'按钮->'结果='按钮->2+6i"
                                        "\n注意事项：\n1.若未点击乘除按键，则默认为加减法运算\n"
                                                    "2.清除结果：将当前操作结果全部清除，重新开始");


}


MainWindowComplex::~MainWindowComplex()
{
    delete ui;
}

char sign='^'; //存储符号字符串类型
QString temp="";
QString tempreal;
QString tempvirtual;
Complex tempc(0,0);    //tempc 始终保持当前运输结果

void MainWindowComplex::on_Button1_clicked()
{
     temp=temp.append('1');
}

void MainWindowComplex::on_Button2_clicked()
{
     temp=temp.append('2');
}



void MainWindowComplex::on_Button3_clicked()
{
     temp=temp.append('3');
}


void MainWindowComplex::on_Button0_clicked()
{
     temp=temp.append('0');
}

void MainWindowComplex::on_Button4_clicked()
{
     temp=temp.append('4');
}


void MainWindowComplex::on_Button5_clicked()
{
     temp=temp.append('5');
}


void MainWindowComplex::on_Button6_clicked()
{
     temp=temp.append('6');
}

void MainWindowComplex::on_Button7_clicked()
{
     temp=temp.append('7');
}

void MainWindowComplex::on_Button8_clicked()
{
     temp=temp.append('8');
}

void MainWindowComplex::on_Button9_clicked()
{
     temp=temp.append('9');
}

void MainWindowComplex::on_Button0_2_clicked()    //小数点
{
    temp=temp.append('.');
}

void MainWindowComplex::on_Button_pos_clicked()
{
    if(temp.isEmpty()){
         temp=temp.append('+');
       }
}

void MainWindowComplex::on_Button_neg_clicked()
{
    if(temp.isEmpty()){
         temp=temp.append('-');
       }
}


void MainWindowComplex::on_Button_point_clicked()   //实际上是求模 model  点求模按键就直接出结果(还没有写完) 求完模后不进行其余操作
{
    if(tempc.real==0 && tempc.virtul==0) return;
    double numreal=tempreal.toDouble();
    double numvirtual=tempvirtual.toDouble();
    if(numreal!=0 || numvirtual!=0)
    {Complex c(numreal,numvirtual);   //先创建当前复数

    double d=c.Model();
    QString s = QString::number(d,'g',6);  //10进制字符串
    ui->answer->setText(s);    //显示求模结果
    }

    else
    {
        double treal=tempc.real;
        double tvirtual=tempc.virtul;
        Complex c(treal,tvirtual);
        double d=c.Model();
        QString s=QString::number(d,'g',6);
        ui->answer->setText(s);
    }
    tempreal="";
    tempvirtual="";
}

void MainWindowComplex::on_Button_multi_clicked()    //乘法运算

{
    bool ok;
//  ui->answer->setText(tempreal);
    if(tempc.real==0 && tempc.virtul==0) return;
    double numreal=tempreal.toDouble(&ok);
    double numvirtual=tempvirtual.toDouble(&ok);
    if(numreal!=0 || numvirtual!=0)
    {Complex * pt= new Complex(numreal,numvirtual);   //先创建当前复数
        tempc=*pt;
    }
    tempreal="";
    tempvirtual="";
    sign='*';

}

void MainWindowComplex::on_Button_div_clicked()
{   if(tempc.real==0 && tempc.virtul==0) return;
    double numreal=tempreal.toDouble();
    double numvirtual=tempvirtual.toDouble();
    if(numreal!=0 || numvirtual!=0)
    {Complex * pt= new Complex(numreal,numvirtual);   //先创建当前复数
        tempc=*pt;}
    tempreal="";
    tempvirtual="";
    sign='%';
}

void MainWindowComplex::on_real_clicked()
{
    tempreal=temp;
    ui->input_real->setText(temp);
    temp="";
}

void MainWindowComplex::on_virtual_2_clicked()
{
    tempvirtual=temp;
    ui->input_virtual->setText(temp);
    temp="";
}

void MainWindowComplex::on_erase_answer_clicked()   //将本次所有操作清空即可
{
    tempreal="";
    tempvirtual="";
    temp="";
    tempc.real=0;
    tempc.virtul=0;
    ui->answer->setText("");
    ui->input_real->setText(temp);
    ui->input_virtual->setText(temp);  // 均清空
}

void MainWindowComplex::on_erase_real_clicked()
{
    temp="";
    tempreal="";
    tempreal=tempreal.append('0');
    ui->input_real->setText(temp);  //将页面清空
}

void MainWindowComplex::on_erase_virtual_clicked()
{
    temp="";
    tempvirtual=tempvirtual.append('0');
    ui->input_virtual->setText(temp);  //将页面清空
}
void MainWindowComplex::on_ans_clicked()   //输出结果
{
    QString display;
    Complex cans(0,0);
    double numreal=tempreal.toDouble();    //按空格之前 先将数字保存好
    double numvirtual=tempvirtual.toDouble();
    Complex * pt= new Complex(numreal,numvirtual);
    if(sign=='*')
    {
      cans=tempc.Multi(*pt);
      display=Complex::ComplexToString(cans);
      tempc=cans;
    }
    if(sign=='%')
    {cans=tempc.Div(*pt);display=Complex::ComplexToString(cans);tempc=cans;}

    if (sign=='^')   //即单纯的加减运算
    {
        cans=tempc.Add(*pt);
        ui->answer->setText(tempreal);
        display=Complex::ComplexToString(cans);
        tempc=cans;        //更新当前结果
    }
    //将结果转换成字符串

    ui->answer->setText(display);    //显示一个字符串
    tempreal="";
    tempvirtual="";
    sign='^';                //将sign 清空(即默认加减运算)
}
//乘法支持和加减的混合运算 而除法不支持 因为除法直接得到double类型的数


