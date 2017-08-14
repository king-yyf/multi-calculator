#ifndef CALWIDGET
#define CALWIDGET

#include <QWidget>
#include "expression.h"
#include "memory.h"

enum FORMAT
{
    FORMAT_FLOAT=1,
    FORMAT_SCIENCE=2,
    FORMAT_MIXED=3
};
//const double EPS=1e-15;
class QLineEdit;
class QToolButton;
class Button;
class QGridLayout;


class CalWidget:public QWidget
{
    Q_OBJECT

public:
    CalWidget(QWidget* parent=0);
    ~CalWidget(){}
    virtual void mySetLayout();
private slots:
    void OrdinaryClicked();
    void FunctionClicked();
    void BspaceClicked();
    void ClearClicked();
    virtual void CAllClicked();
    void PaiClicked();
    //void PowerClicked();
    void EqualClicked();
    void PointClicked();
    //void NegtiveClicked();
    virtual void upClicked();
    virtual void downClicked();
    virtual void showError();
    //virtual void formatButtonClicked();
protected:
    //bool isRound;
    QGridLayout* layout;
    Button* CreatButton(const QString& text, const char* slot);
    int floatNumber;
    QLineEdit* display;
    virtual void formatOutput(int state, double n);
    Button* DigitButton[10];
    Expression expression;
    FORMAT formatState;
    bool EqualState;
    Memory memory;
   // QString exprs;

};

#endif // CALWIDGET

