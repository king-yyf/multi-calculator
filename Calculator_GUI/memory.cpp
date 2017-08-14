
#include "memory.h"

Memory::Memory()
{
    guide=-1;
}

void Memory::clear()
{
    expr.clear();
    resu.clear();
    guide=-1;
}

void Memory::input(QString expression, double result)
{
    guide=expr.size();
    expr.append(expression);
    resu.append(result);
}

void Memory::up(QString &expression, double &result)
{
    if(guide==-1){
        expression="0";
        result=0;
        return;
    }
    --guide;
    if(guide>=0){
       expression=expr[guide];
       result=resu[guide];
    }
    else{
        expression="0";
        result=0;
    }


}

void Memory::down(QString &expression, double &result)
{
    if(guide==expr.size()){
        expression="0";
        result=0;
        return;
    }
    ++guide;
    if(guide<expr.size()){
        expression=expr[guide];
        result=resu[guide];
    }
    else{
        expression="0";
        result=0;
    }


}

