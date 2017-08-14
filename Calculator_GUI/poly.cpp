#include<poly.h>
#include<cmath>
#include<cstring>

Poly * Poly::head=new Poly(0,0);  //类外定义head变量(不能写在头文件中)

void Poly:: AddPoly()
{
    Poly * t0=Poly::head;
    Poly * t=t0->next;    //对this指针进行 操作

    if(t==NULL) {this->next=t; t0->next=this;}
    double e=this->exp;
    double temp;
    while(t!=NULL)
    {
        if(e>t->exp){t=t->next;t0=t0->next;}
        else if(e==t->exp)
        {
            temp=this->coef+t->coef;
            if(temp==0) t0->next=t->next; //存在内存泄露
            else t->coef=temp;
            return;
        }
        else
        {
            this->next=t;
            t0->next=this;
            return;
        }
    }
    this->next=t; t0->next=this;return;
}

QString Poly ::toString(){      //将当前多项式转换成QString类型

    QString str;
    QString temp;
    Poly * t=(Poly::head)->next;
    if(t==NULL) return str="0";
    double num;
    while(t!=NULL)
    {
        num=t->coef;
        if(num<0)
        {
            str=str.append('-');
            num=-num;
        }
        else {str=str.append('+');}
        temp=QString::number(num,'g',6);
        str=str.append(temp);
        num=t->exp;
        if(num==0) {t=t->next;}
        else
        {
            str=str.append('x');
            str=str.append('^');
            if(num<0)
            {
                str=str.append('(');
                temp=QString::number(num,'g',6);
                str=str.append(temp);
                str=str.append(')');
            }
            else
            {temp=QString::number(num,'g',6);
            str=str.append(temp);}
            t=t->next;
        }
    }
    return str;
}

QString Poly:: Diff()            //求导数(静态成员函数)
{
    QString str,temp;
    Poly * t=(Poly::head)->next;
    double numcoef,numexp,num;
    if(t!=NULL && t->exp==0) t=t->next;

    while(t!=NULL)
    {
      numcoef=(t->coef)*(t->exp);
      numexp=t->exp-1;
      if(numexp==-1) {t=t->next;continue;}
      if(numcoef<0)
      {
          str=str.append('-');
          numcoef=-numcoef;
      }
      else str=str.append('+');
      temp=QString::number(numcoef,'g',6);
      str=str.append(temp);        //!!!problem

      if(numexp==0) t=t->next;
      else
      {
          str=str.append('x');
          str=str.append('^');

          if(numexp<0)
          {
              str=str.append('(');
              temp=QString::number(numexp,'g',6);
              str=str.append(temp);
              str=str.append(')');
          }
          else
          {temp=QString::number(numexp,'g',6);
          str=str.append(temp);}
          t=t->next;
      }

    }
    return str;
}








