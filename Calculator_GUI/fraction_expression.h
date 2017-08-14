#ifndef FRACTION_EXPRESSION
#define FRACTION_EXPRESSION
#include<iostream>
#include<QStack>
#include<QString>
using namespace std;

class Fraction_expression;
class Fraction{                                            //分数类
private:
    int numer;                                              //分子
    int denom;                                              //分母
public:
    //friend class Fraction_expression;
    int getnumer();
    int getdenom();
    void Sim(int numer1,int denom1);                          //约分
    void Add(int numer1,int denom1,int numer2,int denom2);    //加法
    void Sub(int numer1,int denom1,int numer2,int denom2);    //减法
    void Mul(int numer1,int denom1,int numer2,int denom2);    //乘法
    void Div(int numer1,int denom1,int numer2,int denom2);    //除法
    void Rec(int numer1,int denom1);                          //求倒数
    double Swi();                                             //转换浮点数
    void Ret();                                               //判错
};

class Fraction_expression{
private:
    QStack<int> s;
    QStack<QChar> c;

public:
    QString input(QString str);
    void oper();


};




#endif // FRACTION_EXPRESSION

