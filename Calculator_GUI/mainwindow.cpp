

#include"mainwindow.h"

Mainwindow::Mainwindow(QWidget* parent):QMainWindow(parent)
{
   cal=new CalWidget(this);
   cal->mySetLayout();
   mainToolBar=new QToolBar(this);
   mainToolBar->setAllowedAreas(Qt::TopToolBarArea);
   advancedMode=mainToolBar->addAction("高级模式",this,SLOT(doAdvancedMode()));
   //inputExpressionMannual=mainToolBar->addAction("手动输入",cal,SLOT(doInputMannual()));
   actAbout=mainToolBar->addAction("关于",this,SLOT(doAbout()));
   actHelp=mainToolBar->addAction("帮助",this,SLOT(doHelp()));
   mainToolBar->setFloatable(false);
   mainToolBar->setMovable(false);
   addToolBar(Qt::TopToolBarArea,mainToolBar);
   setCentralWidget(cal);
   /*QLabel* Space=new QLabel;
   Space->setFixedSize(7,20);
   formatCheckBox=new QCheckBox("科学计数法");
   formatCheckBox->setTristate(true);
   formatCheckBox->setFixedSize(90,20);
   formatCheckBox->setCheckState(Qt::PartiallyChecked);
   statusBar=new QStatusBar;
   statusBar->addWidget(Space);
   statusBar->addWidget(formatCheckBox);
   statusBar->setSizeGripEnabled(false);
   QLabel* formatLabel=new QLabel("有效/小数位数");
   statusBar->addWidget(formatLabel);
   formatEdit=new QLineEdit("6");
   formatEdit->setFixedSize(54,20);
   statusBar->addWidget(formatEdit);
   formatButton=new QPushButton("确定");
   formatButton->setFixedSize(40,20);
   statusBar->addWidget(formatButton);
   setStatusBar(statusBar);*/
   setFixedSize(sizeHint());
   setWindowTitle("计算器");
   acal=new AdvancedMainwindow(this);

   //connect(formatCheckBox,SIGNAL(stateChanged(int)),cal,SLOT(doFormatCheckBoxChanged(int)));
   //connect(formatButton,SIGNAL(clicked()),cal,SLOT(formatButtonClicked()));
}

Mainwindow::~Mainwindow()
{
    delete cal;
}

void Mainwindow::doAdvancedMode()
{
    this->hide();
    acal->show();
}

void Mainwindow::doHelp()
{
    QMessageBox::information(this,"帮助","1.支持的数的范围：大于-1e+16小于1e+16\n"
                                       "2.有效数字位数为6位\n"
                                       "3.“%”为取模运算，不是百分数\n"
                                       "4.不支持计算负数的小数次幂，请先判断结果的符号，再对绝对值求幂");

}
void Mainwindow::doAbout()
{
    QMessageBox::about(this,"关于","设计组成员：\n庞在余，杨云飞，王钰昭，赵瑞雪，杨威峰");
}


