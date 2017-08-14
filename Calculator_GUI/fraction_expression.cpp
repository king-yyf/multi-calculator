#include<iostream>
#include<QString>
#include<QStack>
#include"fraction_expression.h"
using namespace std;


//判错测试函数（同上）
void Fraction::Ret()
{
    cout<<"除数不合法！"<<endl;
    //exit(1);
}


double Fraction::Swi (){

    return ((double) numer/denom);
}

int Fraction::getnumer()
{
    return numer;
}

int Fraction::getdenom()
{
    return denom;
}

void Fraction::Sim(int numer1, int denom1)
{
    if(denom1==0){
        Ret();
        return ;
    }
    int r=numer1%denom1;
    int numer2=numer1;
    int denom2=denom1;
    while(r!=0){
        numer2=denom2;
        denom2=r;
        r=numer2%denom2;
    }
    numer=numer1/denom2;
    denom=denom1/denom2;
    if((numer>0&&denom<0)||(numer<0&&denom<0)){
        numer=(-1)*numer;
        denom=(-1)*denom;
    }
    return ;
}


void Fraction::Add(int numer1, int denom1, int numer2, int denom2)
{
    if(denom1==0||denom2==0){
        Ret();
        return ;
    }
    numer1=numer1*denom2;
    numer2=numer2*denom1;
    numer=numer1+numer2;
    denom=denom1*denom2;
    Sim(numer,denom);
    return ;

}


void Fraction::Sub(int numer1, int denom1, int numer2, int denom2)
{
    if(denom1==0||denom2==0){
        Ret();
        return ;
    }
    numer1=numer1*denom2;
    numer2=numer2*denom1;
    numer=numer1-numer2;
    denom=denom1*denom2;
    Sim(numer,denom);
    return ;

}

void Fraction::Mul(int numer1, int denom1, int numer2, int denom2)
{
    if(denom1==0||denom2==0){
        Ret();
        return ;
    }
    numer=numer1*numer2;
    denom=denom1*denom2;
    Sim(numer,denom);
    return ;

}

void Fraction::Div(int numer1, int denom1, int numer2, int denom2)
{
    if(denom1==0||denom2==0||numer2==0){
        Ret();
        return ;
    }
    Mul(numer1,denom1,denom2,numer2);
    return ;

}

void Fraction::Rec(int numer1, int denom1)
{
    if(denom1==0||numer1==0){
        Ret();
        return ;
    }
    Sim(denom1,numer1);
    return ;
}

void Fraction_expression::oper(){                       //栈顶运算
    int v0,v1,v2,v3;
    QChar ch;
    Fraction Frac;
    ch=c.top();
    c.pop();
    v3=s.top();
    s.pop();
    v2=s.top();
    s.pop();
    v1=s.top();
    s.pop();
    v0=s.top();
    s.pop();
    switch(ch.unicode()){
    case 43:Frac.Add(v0,v1,v2,v3);
        break;
    case 45:Frac.Sub(v0,v1,v2,v3);
        break;
    case 42:Frac.Mul(v0,v1,v2,v3);
        break;
    case 47:Frac.Div(v0,v1,v2,v3);
        break;
    }
    s.push(Frac.getnumer());
    s.push(Frac.getdenom());

}

QString  Fraction_expression::input(QString str){
    QChar ch;
    int d,num,dem;
    QString st1,st2 ;
    str=str+"=";
    c.push('=');
    ch=str[0];
    str.remove(0,1);
    while(ch!='='){
        if(ch.isDigit()){
            d=ch.unicode()-48;
            while(!str.isEmpty()){
                ch=str[0];
                str.remove(0,1);
                if(ch.isDigit())
                    d=d*10+ch.unicode()-48;
                else
                    break;
            }
            s.push(d);
        }
        if(!ch.isDigit())
           switch(ch.unicode()){
            case 40:if(str[0]=='-'){
                   str.remove(0,1);
                   ch=str[0];
                   str.remove(0,1);
                   d=ch.unicode()-48;
                   ch=str[0];
                   str.remove(0,1);
                   while(ch.isDigit()){
                       d=d*10+ch.unicode()-48;
                       ch=str[0];
                       str.remove(0,1);
                      //d=d*10+ch.unicode()-48;
                   }
                   s.push(d*(-1));
                   //str.remove(0,1);
                   ch=str[0];
                   str.remove(0,1);
                   d=ch.unicode()-48;
                   ch=str[0];
                   str.remove(0,1);
                   while(ch.isDigit()){
                       d=d*10+ch.unicode()-48;
                       ch=str[0];
                       str.remove(0,1);
                       //d=d*10+ch.unicode()-48;
                   }
                   s.push(d);
                   //ch=str[0];
                   //str.remove(0,1);
               }
               else
                c.push(ch);
                break;
            case 41:while(c.top()!='(')
                        oper();
                c.pop();                                                        //弹出‘（’
                break;
            case 45:;                                                           //和‘+’优先级相同
            case 43:while(c.top()!='='&&c.top()!='(')
                        oper();
                c.push(ch);
                break;
            case 47:;                                                             //和‘/’优先级相同
            case 42:while(c.top()=='*'||c.top()=='/')
                        oper();
                c.push(ch);
                break;
        }
        if(ch!='='){
           ch=str[0];
           str=str.remove(0,1);
        }
    }
    while(c.top()!='=')
        oper();

    dem=s.top();
    s.pop();
    num=s.top();
    st1=QString::number(num,10);
    st1=st1+"|";
    st2=QString::number(dem,10);
    st1=st1+st2;

    return st1;

}
