#ifndef STATISTICS
#define STATISTICS
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<QString>
#include<sstream>
using namespace std;

class statistics         //统计类
{
    vector <double> sta;   //数据容器
    double sum;          //数据和
    double Dsum;         //平方和
    double ave;         //均值
    double var;         //方差
    double Uvar;       //无偏方差
    double Svar;        //标准差
    double midnum;      //中位数
    double maxmin;     //极差
public:
    statistics(){}
    ~ statistics() {}              //析构函数 ??
   void AddData(double data);    //添加数据
   void Erase();                   //清除上一个数据
    QString Sort();               //对容器中的数据升序排序
    QString rSort();              //降序排序
   double Sum();              //和
   double DSum();             //平方和
    double Average();       //求均值
    double Variance();      //求方差
    double UnVariance();    //无偏方差
    double StaVar();        //标准差
    double Midnum();        //中位数
    double Max_Min();       //极差
    QString toString(double num);    //类型转换
    QString renew();                //更新display
    void empty();                //清空容器
};
#endif // STATISTICS

