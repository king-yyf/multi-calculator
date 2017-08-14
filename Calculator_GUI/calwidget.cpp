#include <QtWidgets>
#include "calwidget.h"
#include "button.h"
#include "mainwindow.h"
//#include "memory.h"
CalWidget::CalWidget(QWidget *parent):QWidget(parent)
{
    floatNumber=6;
    //isRound=false;
    formatState=FORMAT_MIXED;
    EqualState=true;
    display=new QLineEdit("0");
    //display->setMaxLength(15);

    Button* BspaceButton=CreatButton(tr("退格"),SLOT(BspaceClicked()));
    Button* ClearButton=CreatButton(tr("清除"),SLOT(ClearClicked()));
    Button* CAllButton=CreatButton(tr("清除全部"),SLOT(CAllClicked()));
    Button* AddButton=CreatButton(tr("+"),SLOT(OrdinaryClicked()));
    Button* SubButton=CreatButton(tr("-"),SLOT(OrdinaryClicked()));
    Button* MulButton=CreatButton(tr("*"),SLOT(OrdinaryClicked()));
    Button* DivButton=CreatButton(tr("/"),SLOT(OrdinaryClicked()));
    Button* PowButton=CreatButton(tr("^"),SLOT(OrdinaryClicked()));
    Button* SqrtButton=CreatButton(tr("sqrt"),SLOT(FunctionClicked()));
    Button* LnButton=CreatButton(tr("ln"),SLOT(FunctionClicked()));
    Button* EqualButton=CreatButton(tr("="),SLOT(EqualClicked()));
    Button* PaiButton=CreatButton(tr("Pai"),SLOT(PaiClicked()));
    Button* PointButton=CreatButton(tr("."),SLOT(PointClicked()));
    //Button* LBBracketButton=CreatButton(tr("{"),SLOT(OrdinaryClicked()));
    //Button* RBBracketButton=CreatButton(tr("}"),SLOT(OrdinaryClicked()));
    Button* UpButton=CreatButton("↑",SLOT(upClicked()));
    Button* DownButton=CreatButton("↓",SLOT(downClicked()));
    Button* LBracketButton=CreatButton(tr("("),SLOT(OrdinaryClicked()));
    Button* RBracketButton=CreatButton(tr(")"),SLOT(OrdinaryClicked()));
    Button* ModButton=CreatButton(tr("%"),SLOT(OrdinaryClicked()));
    for(int i=0;i<10;++i)
    {
        DigitButton[i]=CreatButton(QString::number(i),SLOT(OrdinaryClicked()));
    }
    layout=new QGridLayout;
    layout->setSizeConstraint(QLayout::SetFixedSize);
    layout->addWidget(display,0,0,1,6);
    layout->addWidget(BspaceButton,1,0,1,2);
    layout->addWidget(ClearButton, 1, 2, 1, 2);
    layout->addWidget(CAllButton, 1, 5, 1, 1);
    for(int i=1;i<10;++i)
    {
        int r=4-(i-1)/3;
        int c=(i-1)%3;
        layout->addWidget(DigitButton[i],r,c);
    }
    layout->addWidget(AddButton,5,3);
    layout->addWidget(SubButton,4,3);
    layout->addWidget(MulButton,3,3);
    layout->addWidget(DivButton,2,3);
    layout->addWidget(SqrtButton,2,5);
    layout->addWidget(LnButton,3,5);
    layout->addWidget(PowButton,4,5);
    layout->addWidget(PaiButton,5,5);
    layout->addWidget(DigitButton[0],5,0);
    layout->addWidget(EqualButton,5,2);
    layout->addWidget(PointButton,5,1);
    //layout->addWidget(LBBracketButton,1,4);
    //layout->addWidget(RBBracketButton,2,4);
    layout->addWidget(UpButton,1,4);
    layout->addWidget(DownButton,2,4);
    layout->addWidget(LBracketButton,3,4);
    layout->addWidget(RBracketButton,4,4);
    layout->addWidget(ModButton,5,4);
}
Button* CalWidget::CreatButton(const QString &text, const char *slot)
{
    Button* button=new Button(text);
    connect(button,SIGNAL(clicked()),this,slot);
    return button;
}

void CalWidget::formatOutput(int state, double n)
{
    /*if(isRound)
    {
    double eps=1;
    double tn=n;

    switch(state)
    {
    case FORMAT_FLOAT:
    case FORMAT_SCIENCE:
    {
        for(int i=0;i<floatNumber;++i)
        {
            eps*=0.1;
        }
        n=myRound(n,floatNumber,eps);
        break;
    }
    case FORMAT_MIXED:
    {
        int j=0;
        for(;tn>=1;++j)
        {
            tn*=0.1;
        }
        for(int i=0;i<floatNumber-j;++i)
        {
            eps*=0.1;
        }
        n=myRound(n,floatNumber-j,eps);
        break;
    }
    }
    }*/
    switch(state)
    {
    case FORMAT_FLOAT:
        display->setText(QString::number(n,'f',floatNumber));
        break;
    case FORMAT_SCIENCE:
        display->setText(QString::number(n,'e',floatNumber));
        break;
    case FORMAT_MIXED:
        display->setText(QString::number(n,'g',floatNumber));
        break;
    }
}

void CalWidget::mySetLayout()
{
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    QFont font = display->font();
    font.setPointSize(font.pointSize() + 8);
    display->setFont(font);
    setLayout(layout);
}
/*CalWidget::~CalWidget()
{
    delete display;
}*/

void CalWidget::OrdinaryClicked()
{
    Button* t=qobject_cast<Button*>(sender());
    if(display->text()=="0"||EqualState)
    {
        display->setText(t->text());
        EqualState=false;
    }
    else
    {
        display->setText(display->text()+t->text());
    }
}

void CalWidget::FunctionClicked()
{
    Button* t=qobject_cast<Button*>(sender());
    if(display->text()=="0"||EqualState)
    {
        display->setText(t->text()+"(");
        EqualState=false;
    }
    else
    {
        display->setText(display->text()+t->text()+"(");
    }
}

void CalWidget::BspaceClicked()
{
    display->backspace();
    QString t=display->text();
    if(t.isEmpty())
    {
        display->setText("0");
    }
}

void CalWidget::ClearClicked()
{
    display->setText("0");
    EqualState=true;
}

void CalWidget::CAllClicked()
{
    display->setText("0");
    EqualState=true;
    memory.clear();
}

void CalWidget::PaiClicked()
{
    if(display->text()=="0"||EqualState)
    {
        display->setText(QString::number(PAI,'f',17));
        EqualState=false;

    }
    else
    {
        display->setText(display->text()+QString::number(PAI,'f',17));
    }
}

void CalWidget::EqualClicked()
{
    if(EqualState)
        return;
    QString t=display->text();
    EqualState=true;
    //if(t[0].isNumber()||t[0]=='('||t[0]==' '||t[0]=='-'||t[0]=='.')
   // {
    expression.SetExpression(display->text());
    if(expression.LegalAndCal())
    {
        double tresult=expression.GetResult();
        if(tresult!=tresult||tresult+1==tresult)
           showError();
        else
        {
            memory.input(t,tresult);
            formatOutput(formatState,expression.GetResult());
        }
        //display->setText(QString::number(expression.GetResult(),'e',floatNumber));

    }
    else
    {
        showError();
    }
    //}
    //else
    //{
    //    display->setText("表达式错误或数值溢出！");
    //}
}

void CalWidget::PointClicked()
{
    if(EqualState)
    {
        display->setText("0.");
        EqualState=false;
    }
    else
    {
        display->setText(display->text()+".");
    }
}





void CalWidget::upClicked()
{
    QString exptemp;
    double restemp;
    memory.up(exptemp,restemp);
    display->setText(exptemp);
    EqualState=false;
}

void CalWidget::downClicked()
{
    QString exptemp;
    double restemp;
    memory.down(exptemp,restemp);
    display->setText(exptemp);
    EqualState=false;
}

void CalWidget::showError()
{
    display->setText("表达式错误或数值溢出");
}

/*void CalWidget::NegtiveClicked()
{
    if(display->text()=="0")
    {
        display->setText(" -(");

    }
    else
    {
        display->setText(display->text()+" -(");
    }
}*/

/*void CalWidget::formatButtonClicked()
{
    bool ok;
    int t=qobject_cast<Mainwindow*>(this->parent())->formatEdit->text().toInt(&ok);
    if(ok==true&&t<=15&&t>=0)
    {
        floatNumber=t;
    }
    else
    {
        qobject_cast<Mainwindow*>(this->parent())->formatEdit->setText(QString::number(floatNumber));
        QMessageBox::information(this,"错误","输入数字错误！\n"
                                           "请输入大于等于0小于等于15的整数！");
    }
}*/

