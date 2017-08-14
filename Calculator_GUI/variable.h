#ifndef VARIABLE
#define VARIABLE
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<QString>
#include<sstream>
//#include"sdf_mainwindow.h"
using namespace std;

class Variable{
    QString name;
    double value;
public:
    void setName(QString arg1);
    void setValue(double arg1);
    QString getName();
    double getValue();
};

class VariableDao{
    vector <Variable> vec;
public:
    void addVar(Variable arg1);
    void delVar();
    void clearVar();
    QString displayVar();
    QString toString(double num);
    QString trans(QString s);
    int findByName(QString s);
    void modifyVar(int loc,double n);
};

#endif // VARIABLE

