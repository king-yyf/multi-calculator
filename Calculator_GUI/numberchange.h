#ifndef NUMBERCHANGE_H
#define NUMBERCHANGE_H

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<QString>
#include<sstream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

#include <cstring>
#include <iostream>

using namespace std;

class numberchange {        //进制类

public:
    numberchange(){}
    ~numberchange(){}     //析构函数
    string tenTwo(int)    ;       //十进制转二进制
    string tenEight(int)  ;       //十进制转八进制
    string tenSixteen(int) ;      //十进制转十六进制
    int twoEight(int)    ;       //二进制转八进制
    int twoTen(int)  ;            //二进制转十进制
    string twoSixteen(int);       //二进制转十六进制
    int eightTen(int);           //八进制转十进制
    string eightSixteen(int);     //八进制转十六进制
    string eightTwo(int);        //八进制转二进制
    char exchange(int);           //十六进制特殊标符
    void Erase();                 //清除上一个数据
    void cleanStr();             //初始化str
};


#endif // NUMBERCHANGE_H
