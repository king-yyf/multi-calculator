
#ifndef EXPRESSION
#define EXPRESSION
#include <QString>
#include <stack>
#include <queue>
const int FuncNumber=8+15;
const double PAI=3.14159265358979323;
//const double EPS=1e-15;
using std::stack;
const QString function[FuncNumber]=
{
    "","","","","","","","",
    "sin",
    "cos",
    "tan",
    "arcsin",
    "arccos",
    "arctan",
    "exp",
    "sqrt",
    "ln",
    "log10",
    "ceil",
    "floor",
    "abs",
    "fac",
    "log2"
};//Function array which can be added.
const int PRIORITY[7][7]=
{  // +  -  *  /  (  ^  %
    { 0, 0,-1,-1, 1,-1,-1},//+
    { 0, 0,-1,-1, 1,-1,-1},//-
    { 1, 1, 0, 0, 1,-1, 0},//*
    { 1, 1, 0, 0, 1,-1, 0},//÷
    {-1,-1,-1,-1, 0,-1,-1},//(
    { 1, 1, 1, 1, 1, 1, 1},//^
    { 1, 1, 0, 0, 1,-1, 0} //%
};
//double myRound(double indata,int precision,double eps);
class Expression
{
public:
    Expression(QString s=""):expstring(s),result(0),isRad(true){sc.push(4);}
    bool LegalAndCal();//judge the validity of the expression and calculate.
    double GetResult(){return result;}
    void SetExpression(QString s);
    void ResetExpresion(){expstring="";}
    bool isRad;
private:
    bool MyToDouble(const QString&);
    bool opcal(int currentop);
    double myBasicCal(double,double,int);//calculation of "+,-,*,/"
    int FunNum(int b, int m);
    double FunCal(int funcnum, double x);//function calculation
    double mypop(stack<double>& s){double t=s.top();s.pop();return t;}//just an enhanced pop
    //bool ComPri(char a,char b);
    stack<double> sn;
    stack<int> sc;
    QString expstring;//QString is similar to string.
    //bool legal;
    double result;

};

#endif // EXPRESSION

