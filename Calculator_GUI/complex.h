#ifndef COMPLEX_H
#define COMPLEX_H

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<QString>

class Complex
{
public:
    Complex(double r,double v):real(r),virtul(v){}
    ~Complex(){}
    Complex Add(Complex);
    Complex& Multi(Complex);
    Complex Div(Complex);
    double Model();
    static QString ComplexToString(Complex);

    double real;     //实数
    double virtul;      //虚数
};

#endif // COMPLEX_H

