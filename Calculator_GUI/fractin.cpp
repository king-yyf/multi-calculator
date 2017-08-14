#include "fractin.h"
#include "ui_fractin.h"
#include"fraction_expression.h"

fractin::fractin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fractin)
{
    ui->setupUi(this);
    mainToolBar=new QToolBar(this);
    mainToolBar->setAllowedAreas(Qt::TopToolBarArea);
    setWindowTitle("分数");
    actHelp=mainToolBar->addAction("帮助",this,SLOT(doHelp()));
    addToolBar(mainToolBar);
    mainToolBar->setFloatable(false);
    mainToolBar->setMovable(false);
    setFixedSize(249,279);
   // error="格式不支持！";
}

void fractin::doHelp()
{
    QMessageBox::information(this,"帮助","输入格式：\n1.表达式仅支持分数运算;\n"
                                       "2. ‘|’为分数线;\n"
                                       "3. 负数应加括号。如：-3|4应写成(-3|4);\n"
                                       "4.整数，浮点数可通过“转换”按钮转化为分数;\n"
                                          "分数也可通过“转换”按钮转化为浮点");
}

fractin::~fractin()
{
    delete ui;
}

//QString text;


void fractin::on_pushButton0_clicked()
{
    text=text.append('0');
    ui->show->setText(text);

}

void fractin::on_pushButton1_clicked()
{
    text=text.append('1');
    ui->show->setText(text);

}

void fractin::on_pushButton2_clicked()
{
    text=text.append('2');
    ui->show->setText(text);
}

void fractin::on_pushButton3_clicked()
{
    text=text.append('3');
    ui->show->setText(text);
}

void fractin::on_pushButton4_clicked()
{
    text=text.append('4');
    ui->show->setText(text);
}

void fractin::on_pushButton5_clicked()
{
    text=text.append('5');
    ui->show->setText(text);
}

void fractin::on_pushButton6_clicked()
{
    text=text.append('6');
    ui->show->setText(text);
}

void fractin::on_pushButton7_clicked()
{
    text=text.append('7');
    ui->show->setText(text);
}

void fractin::on_pushButton8_clicked()
{
    text=text.append('8');
    ui->show->setText(text);
}

void fractin::on_pushButton9_clicked()
{
    text=text.append('9');
    ui->show->setText(text);
}

void fractin::on_cancel_clicked()
{
    if(text.isEmpty())
         ui->show->setText(text);
    else{
         text=text.remove(text.size()-1,1);
         ui->show->setText(text);
    }

}

void fractin::on_divide_clicked()
{
    text=text.append('/');
    ui->show->setText(text);

}

void fractin::on_plus_clicked()
{
    text=text.append('+');
    ui->show->setText(text);
}

void fractin::on_mutiply_clicked()
{
    text=text.append('*');
    ui->show->setText(text);
}

void fractin::on_subtract_clicked()
{
    text=text.append('-');
    ui->show->setText(text);
}

void fractin::on_fraction_line_clicked()
{
    text=text.append('|');
    ui->show->setText(text);
}

void fractin::on_left_bracket_clicked()
{
    text=text.append('(');
    ui->show->setText(text);
}

void fractin::on_right_bracket_clicked()
{
    text=text.append(')');
    ui->show->setText(text);
}

void fractin::on_empty_clicked()
{
    text="";
    ui->show->setText(text);

}

void fractin::on_equal_clicked()
{
    QStack<QChar> t;
    int d=0;
    QString str=text;
    QChar ch=text[0];
    text.remove(0,1);
    if((!ch.isDigit()&&ch!='(')||text.isEmpty()){
        text="格式不支持！";
        ui->show->setText(text);
        return;
    }
    while(!text.isEmpty()){
        if(ch.isDigit()){
            while(ch.isDigit()&&!text.isEmpty()){
              ch=text[0];
              text.remove(0,1);
            }
            if(ch!='|'||text.isEmpty()){
              text="格式不支持！";
              ui->show->setText(text);
              return;
            }
            ch=text[0];
            text.remove(0,1);
            if(!ch.isDigit()){
                text="格式不支持！";
                ui->show->setText(text);
                return;
            }
            while(ch.isDigit()&&!text.isEmpty()){
                d=d*10+ch.unicode()-48;
                ch=text[0];
                text.remove(0,1);
            }
            if(ch.isDigit())
                d=d*10+ch.unicode()-48;
            if(d==0){
                text="分母不能为零！";
                ui->show->setText(text);
                return;
            }
            if(ch=='.'||ch=='('||ch=='|'){
                text="格式不支持！";
                ui->show->setText(text);
                return;
            }
            continue;
        }
        if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
           if(text.isEmpty()){
               text="格式不支持！";
               ui->show->setText(text);
               return;
           }
           ch=text[0];
           text.remove(0,1);
           if(!(ch.isDigit()||ch=='(')||(ch.isDigit()&&text.isEmpty())){
               text="格式不支持！";
               ui->show->setText(text);
               return;
           }
           continue;
        }
        if(ch=='('){
            t.push(ch);
            if(text.isEmpty()){
                text="格式不支持！";
                ui->show->setText(text);
                return;
            }
            ch=text[0];
            text.remove(0,1);
            if(!ch.isDigit()&&ch!='('&&ch!='-'){
                text="格式不支持！";
                ui->show->setText(text);
                return;
            }
            if(ch=='-'){
                if(text.isEmpty()){
                    text="格式不支持！";
                    ui->show->setText(text);
                    return;
                }
                ch=text[0];
                text.remove(0,1);
                if(!ch.isDigit()){
                    text="格式不支持！";
                    ui->show->setText(text);
                    return;
                }
                while(ch.isDigit()&&!text.isEmpty()){
                    ch=text[0];
                    text.remove(0,1);
                }
                if(text.isEmpty()||ch!='|'){
                    text="格式不支持！";
                    ui->show->setText(text);
                    return;
                }

                ch=text[0];
                text.remove(0,1);
                while(ch.isDigit()&&!text.isEmpty()){
                    ch=text[0];
                    text.remove(0,1);
                }
                if(text.isEmpty()&&ch.isDigit()){
                    text="格式不支持！";
                    ui->show->setText(text);
                    return;
                }
                if(ch!=')'){
                    text="格式不支持！";
                    ui->show->setText(text);
                    return;
                }
                t.pop();
                if(!text.isEmpty()){
                ch=text[0];
                text.remove(0,1);
                if(ch.isDigit()||ch=='.'||ch=='('||ch=='|'){
                    text="格式不支持！";
                    ui->show->setText(text);
                    return;
                }
                }
                else
                    ch='0';
            }
            continue;
        }
        if(ch==')'){
            if(t.isEmpty()){
                text="格式不支持！";
                ui->show->setText(text);
                return;
            }
            else{
                t.pop();
                if(!text.isEmpty()){
                    ch=text[0];
                    text.remove(0,1);
                    if(ch!='+'&&ch!='-'&&ch!='*'&&ch!='/'&&ch!=')'){
                        text="格式不支持！";
                        ui->show->setText(text);
                        return;
                    }
                }

                continue;
            }
        }
        text="格式不支持！";
        ui->show->setText(text);
        return;
    }
    if(ch!=')'&&!ch.isDigit()){
        text="格式不支持！";
        ui->show->setText(text);
        return;
    }
    if(ch==')'){
        if(t.isEmpty()){
            text="格式不支持！";
            ui->show->setText(text);
            return;
        }
        else
           t.pop();
    }
    if(!t.isEmpty()){
        text="格式不支持！";
        ui->show->setText(text);
        return;
    }
   text=str;
   Fraction_expression f;
   text=f.input(text);
   ui->show->setText(text);


}

void fractin::on_point_clicked()
{
    text=text.append('.');
    ui->show->setText(text);

}

void fractin::on_simplify_clicked()
{
    int d=0,c=0;
    bool negtive=false;
    if(text.isEmpty()){
        text="格式不支持！";
        ui->show->setText(text);
        return;
    }
    QChar ch=text[0];
    text.remove(0,1);
    if(ch=='-'){
        negtive=true;
        if(text.isEmpty()){
            text="格式不支持！";
            ui->show->setText(text);
            return;
        }
        ch=text[0];
        text.remove(0,1);
    }
    if(!ch.isDigit()){
        text="格式不支持！";
        ui->show->setText(text);
        return;
    }
    while(ch.isDigit()&&!text.isEmpty()){
        d=d*10+ch.unicode()-48;
        ch=text[0];
        text.remove(0,1);

    }
    if(text.isEmpty()||ch!='|'){
        text="格式不支持！";
        ui->show->setText(text);
        return;
    }
    ch=text[0];
    text.remove(0,1);
    if(!ch.isDigit()){
        text="格式不支持！";
        ui->show->setText(text);
        return;
    }
    while(ch.isDigit()&&!text.isEmpty()){
        c=c*10+ch.unicode()-48;
        ch=text[0];
        text.remove(0,1);
    }
    if(ch.isDigit()){
        c=c*10+ch.unicode()-48;
        Fraction f;
        f.Sim(d,c);
        if(negtive==true)
            text="-"+QString::number(f.getnumer(),10)+"|"+QString::number(f.getdenom(),10);
        else
            text=QString::number(f.getnumer(),10)+"|"+QString::number(f.getdenom(),10);
        ui->show->setText(text);
        return;
    }
    else{
        text="格式不支持！";
        ui->show->setText(text);
        return;
    }

}

void fractin::on_switchButton_clicked()
{
    int d=0,c=0;
    bool negtive=false;
    if(text.isEmpty()){
        text="格式不支持！";
        ui->show->setText(text);
        return;
    }
    QChar ch=text[0];
    text.remove(0,1);
    if(ch=='-'){
        negtive=true;
        if(text.isEmpty()){
            text="格式不支持！";
            ui->show->setText(text);
            return;
        }
        ch=text[0];
        text.remove(0,1);
    }
    if(!ch.isDigit()){
        text="格式不支持！";
        ui->show->setText(text);
        return;
    }
    while(ch.isDigit()&&!text.isEmpty()){
        d=d*10+ch.unicode()-48;
        ch=text[0];
        text.remove(0,1);
    }
    if(ch.isDigit()){
        d=d*10+ch.unicode()-48;
        if(negtive==false)
            text=QString::number(d,10)+"|"+QString::number(1,10);
        else
            text="-"+QString::number(d,10)+"|"+QString::number(1,10);
        ui->show->setText(text);
        return;
    }
    if(ch=='|'){
        ch=text[0];
        text.remove(0,1);
        if(!ch.isDigit()){
            text="格式不支持！";
            ui->show->setText(text);
            return;
        }
        while(ch.isDigit()&&!text.isEmpty()){
            c=c*10+ch.unicode()-48;
            ch=text[0];
            text.remove(0,1);
        }
        if(ch.isDigit()){
            c=c*10+ch.unicode()-48;
            float l=(float)d/c;
            if(negtive==false)
                text=QString("%1").arg(l);
            else
                text="-"+QString("%1").arg(l);
            ui->show->setText(text);
            return;
        }
        else{
            text="格式不支持！";
            ui->show->setText(text);
            return;
        }

    }
    if(ch=='.'){
        c=pow(10,text.length());
        ch=text[0];
        text.remove(0,1);
        if(!ch.isDigit()){
            text="格式不支持！";
            ui->show->setText(text);
            return;
        }
        while(ch.isDigit()&&!text.isEmpty()){
            d=d*10+ch.unicode()-48;
            ch=text[0];
            text.remove(0,1);
        }
        if(ch.isDigit()){
            d=d*10+ch.unicode()-48;
            Fraction f;
            f.Sim(d,c);
            if(negtive==false)
                text=QString::number(f.getnumer(),10)+"|"+QString::number(f.getdenom(),10);
            else
                text="-"+QString::number(f.getnumer(),10)+"|"+QString::number(f.getdenom(),10);
                //text=QString::number(f.getdenom(),10);
            ui->show->setText(text);
            return;
        }
        else{
            text="格式不支持！";
            ui->show->setText(text);
            return;
        }

    }

}

