#ifndef MEMORY
#define MEMORY

#include <iostream>
#include<QString>
#include<QStringList>
#include<QList>
using namespace std;

class Memory
{
private:
    QStringList expr;
    QList<double> resu;
    int guide;

public:
    Memory();
    void clear();
    void input(QString expression,double result);
    void up(QString& expression,double& result);
    void down(QString& expression,double& result);

};

#endif // MEMORY

