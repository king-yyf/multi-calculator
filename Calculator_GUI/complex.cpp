#include<complex.h>
#include<cmath>
#include<cstring>


QString Complex::ComplexToString(Complex f)
{
    QString s="";
    QString s1;
    QString s2;
    if(f.real==0 && f.virtul==0) {s=s.append('0');return s;}
   if(f.real<0){ s=s.append('-');s1=QString::number(-f.real,'g',6);}
    else {s1=QString::number(f.real,'g',6);}
    s=s.append(s1);

    if(f.virtul<0)
    { s=s.append('-');s2=QString::number(-f.virtul,'g',6);;s=s.append(s2);s=s.append('i');}
    else if(f.virtul==0){return s;}
         else {s=s.append('+');s2=QString::number(f.virtul,'g',6); s=s.append(s2);s=s.append('i');}
    return s;
    /*

    if(f.real<0){ s=s.append('-');s1=QString::number(-f.real,'g',6);}
      else { s1=QString::number(f.real,'g',6);}
      s=s.append(s1);

      if(f.virtul<0)
      { s=s.append('-');s2=QString::number(-f.virtul,'g',6); s=s.append(s2);s=s.append('i');}
      else if(f.virtul==0){return s;}
           else {s=s.append('+');s2=QString::number(f.virtul,'g',6); s=s.append(s2);s=s.append('i');}
      return s;*/
}

Complex Complex::Add(Complex f)
{
    real=real+f.real;
    virtul=virtul+f.virtul;
    return (* this);
}

Complex& Complex::Multi(Complex f)
{
    double r=real;
    real=real*f.real-virtul*f.virtul;  //调试了好几个小时 竟然是一个非常愚蠢的错误 real的值已经更改了 就不能用了
    virtul=r*f.virtul+f.real*virtul;

    return ( *this);
}

Complex Complex:: Div(Complex f)
{
    double d,d1,d2;
    QString s="";
    QString s1;
    QString s2;
    d=f.real*f.real+f.virtul*f.virtul;
    d1=(real*f.real+f.virtul*virtul)*1.0/d;
    d2=(-real*f.virtul+virtul*f.real)*1.0/d;

    real=d1;
    virtul=d2;
    return ( *this);;
}

double Complex::Model()
{
    double d;
    d=real*real+virtul*virtul;
    d=sqrt(d);
    return d;
}
