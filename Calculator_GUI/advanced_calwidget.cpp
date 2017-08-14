//#include <QLabel>
//#include <QLayout>
#include <QtWidgets>
#include "advanced_calwidget.h"
#include "randmainwindow.h"
#include "advanced_mainwindow.h"
#include "fractin.h"
#include "equationmainwindow.h"
#include "st_mainwindow.h"
#include "mainwindow_complex.h"
#include "mainwindow_poly.h"

AdvancedCalwidget::AdvancedCalwidget(QWidget *parent):CalWidget(parent)
{
    Button* SinButton=CreatButton("sin",SLOT(FunctionClicked()));
    Button* CosButton=CreatButton("cos",SLOT(FunctionClicked()));
    Button* TanButton=CreatButton("tan",SLOT(FunctionClicked()));
    Button* ArcsinButton=CreatButton("arcsin",SLOT(FunctionClicked()));
    Button* ArccosButton=CreatButton("arccos",SLOT(FunctionClicked()));
    Button* ArctanButton=CreatButton("arctan",SLOT(FunctionClicked()));
    Button* ExpButton=CreatButton("exp",SLOT(FunctionClicked()));
    Button* Log10Button=CreatButton("log10",SLOT(FunctionClicked()));
    Button* Log2Button=CreatButton("log2",SLOT(FunctionClicked()));
    Button* CeilButton=CreatButton("ceil",SLOT(FunctionClicked()));
    Button* FloorButton=CreatButton("floor",SLOT(FunctionClicked()));
    Button* AbsButton=CreatButton("abs",SLOT(FunctionClicked()));
    Button* FacButton=CreatButton("fac",SLOT(FunctionClicked()));
    Button* IButton=CreatButton("i",SLOT(iClicked()));
    Button* FractionButton=CreatButton("x|y",SLOT(fractionClicked()));
    Button* AnswerButton=CreatButton("Ans",SLOT(AnsClicked()));
    Button* RandButton=CreatButton("rand",SLOT(RandClicked()));
    Button* EquationButton=CreatButton("x=?",SLOT(equationClicked()));
    Button* StatisticButton=CreatButton("∑x",SLOT(statisticClicked()));
    Button* PolyButton=CreatButton("ax+bx",SLOT(polyClicked()));

    //QLabel* label=new QLabel("\t函数功能键区\t");
    //QFont font=label->font();
    //font.setPointSize(font.pointSize()+2);
    //label->setFont(font);
    //label->setFrameShape(QFrame::StyledPanel);

    resultDisplay=new QLineEdit("0");
    QFont font = resultDisplay->font();
    font.setPointSize(font.pointSize() + 8);
    resultDisplay->setAlignment(Qt::AlignRight);
    resultDisplay->setReadOnly(true);
    resultDisplay->setFont(font);

    QGridLayout* rlayout=new QGridLayout;
    rlayout->addWidget(resultDisplay,0,0,1,4);
    rlayout->addWidget(SinButton,1,0);
    rlayout->addWidget(CosButton,1,1);
    rlayout->addWidget(TanButton,1,2);
    rlayout->addWidget(ArcsinButton,2,0);
    rlayout->addWidget(ArccosButton,2,1);
    rlayout->addWidget(ArctanButton,2,2);
    rlayout->addWidget(ExpButton,3,0);
    rlayout->addWidget(Log10Button,3,1);
    rlayout->addWidget(Log2Button,3,2);
    rlayout->addWidget(CeilButton,4,0);
    rlayout->addWidget(FloorButton,4,1);
    rlayout->addWidget(AbsButton,4,2);
    rlayout->addWidget(AnswerButton,5,0);
    rlayout->addWidget(FacButton,5,1);
    rlayout->addWidget(IButton,5,2);
    rlayout->addWidget(FractionButton,5,3);
    rlayout->addWidget(RandButton,3,3);
    rlayout->addWidget(EquationButton,1,3);
    rlayout->addWidget(StatisticButton,2,3);
    rlayout->addWidget(PolyButton,4,3);

    alayout=new QHBoxLayout;
    QFrame* line=new QFrame(this);
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);
    //seperator->setFrameShape(QFrame::VLine);
    alayout->addLayout(layout);;
    //alayout->addSpacing(10);
    alayout->addWidget(line);
    alayout->addLayout(rlayout);


}

void AdvancedCalwidget::mySetLayout()
{

    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setFixedSize(286,30);
    QFont font = display->font();
    font.setPointSize(font.pointSize() + 5);
    display->setFont(font);
    setLayout(alayout);
}

void AdvancedCalwidget::RandClicked()
{
    RandMainwindow* randmwindow=new RandMainwindow(this);
    randmwindow->setAttribute(Qt::WA_DeleteOnClose,true);
    randmwindow->show();
}

void AdvancedCalwidget::formatEditChanged(int val)
{
    floatNumber=val;
    QString t=resultDisplay->text();
    bool ok;
    double tn=t.toDouble(&ok);
    if(ok)
    {
        formatOutput(formatState,tn);
    }
}
void AdvancedCalwidget::doFormatCheckBoxChanged(int State)
{
    if(State==Qt::Checked)
        formatState=FORMAT_SCIENCE;
    else if(State==Qt::Unchecked)
        formatState=FORMAT_FLOAT;
    else
        formatState=FORMAT_MIXED;
    QString t=resultDisplay->text();
    bool ok;
    double tn=t.toDouble(&ok);
    if(ok)
    {
        formatOutput(formatState,tn);
    }
}

void AdvancedCalwidget::fractionClicked()
{
    fractin* fraction=new fractin(this);
    fraction->setAttribute(Qt::WA_DeleteOnClose,true);
    fraction->show();
}

void AdvancedCalwidget::equationClicked()
{
    EquationMainWindow* equation=new EquationMainWindow(this);
    equation->setAttribute(Qt::WA_DeleteOnClose,true);
    equation->show();
}

void AdvancedCalwidget::statisticClicked()
{
    ST_MainWindow* stmainwindow=new ST_MainWindow(this);
    stmainwindow->setAttribute(Qt::WA_DeleteOnClose,true);
    stmainwindow->show();
}

void AdvancedCalwidget::iClicked()
{
    MainWindowComplex* complexWindow=new MainWindowComplex(this);
    complexWindow->setAttribute(Qt::WA_DeleteOnClose,true);
    complexWindow->show();
}

void AdvancedCalwidget::polyClicked()
{
    MainWindowPoly* poly=new MainWindowPoly(this);
    poly->setAttribute(Qt::WA_DeleteOnClose,true);
    poly->show();
}

void AdvancedCalwidget::showError()
{
    resultDisplay->setText("表达式错误或数值溢出");
}
/*void AdvancedCalwidget::formatButtonClicked()
{
    bool ok;
    int t=qobject_cast<AdvancedMainwindow*>(this->parent())->formatEdit->text().toInt(&ok);
    if(ok==true&&t<=15&&t>=0)
    {
        floatNumber=t;
    }
    else
    {
        qobject_cast<AdvancedMainwindow*>(this->parent())->formatEdit->setText(QString::number(floatNumber));
        QMessageBox::information(this,"错误","输入数字错误！\n"
                                           "请输入大于等于0小于等于15的整数！");
    }
}*/

void AdvancedCalwidget::radBoxStatusChanged(int State)
{
    if(State==Qt::Checked)
        expression.isRad=false;
    else
        expression.isRad=true;
    QString t=this->resultDisplay->text();
    bool ok;
    double tn=t.toDouble(&ok);
    if(ok)
    {
        switch(expression.isRad)
        {
        case true:
        {
            double t=fmod(tn/180*PAI,2*PAI);
            if(t<0)
                t+=2*PAI;
            formatOutput(formatState,t);
            break;
        }
        case false:
        {
            double t=fmod(tn/PAI*180,360);
            if(t<0)
                t+=360;
            formatOutput(formatState,t);
            break;
        }
        }
    }
}

void AdvancedCalwidget::CAllClicked()
{
    display->setText("0");
    resultDisplay->setText("0");
    EqualState=true;
    memory.clear();
}

void AdvancedCalwidget::AnsClicked()
{
    if(display->text()=="0"||EqualState)
    {
        display->setText(resultDisplay->text());
        EqualState=false;
    }
    else
    {
        display->setText(display->text()+resultDisplay->text());
    }
}

void AdvancedCalwidget::formatOutput(int state, double n)
{
    switch(state)
    {
    case FORMAT_FLOAT:
        resultDisplay->setText(QString::number(n,'f',floatNumber));
        break;
    case FORMAT_SCIENCE:
        resultDisplay->setText(QString::number(n,'e',floatNumber));
        break;
    case FORMAT_MIXED:
        resultDisplay->setText(QString::number(n,'g',floatNumber));
        break;
    }
}
void AdvancedCalwidget::doInputMannual()
{
    EqualState=true;
    bool ok;
    QString text=QInputDialog::getText(this,tr("手动输入"),tr("表达式（格式请查看“帮助”）"),
                                       QLineEdit::Normal,tr("例:-1+sin(sqrt(2)+1)"),&ok);
    if(ok&&!text.isEmpty())
    {
    expression.SetExpression(text);
    if(expression.LegalAndCal())
    {
        double tresult=expression.GetResult();
        if(tresult!=tresult||tresult+1==tresult)
            showError();
        else
        {
            memory.input(text,tresult);
            display->setText(text);
            formatOutput(formatState,expression.GetResult());
        }
    }
    else
    {
       showError();
    }
    }
}

void AdvancedCalwidget::upClicked()
{
    QString exptemp;
    double restemp;
    memory.up(exptemp,restemp);
    display->setText(exptemp);
    formatOutput(formatState,restemp);
    EqualState=false;
}

void AdvancedCalwidget::downClicked()
{
    QString exptemp;
    double restemp;
    memory.down(exptemp,restemp);
    display->setText(exptemp);
    formatOutput(formatState,restemp);
    EqualState=false;
}

/*void AdvancedCalwidget::isRoundChanged(int state)
{
    switch(state)
    {
    case Qt::Checked:
        isRound=true;
        break;
    case Qt::Unchecked:
        isRound=false;
        break;
    }
}*/
