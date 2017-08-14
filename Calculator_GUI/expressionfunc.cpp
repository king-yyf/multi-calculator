/* you do not need to understand these definitions of functions.
 * A knowledge of how to use them is required.*/
/* But if you find any fault or unreasonable codes in this file,you can also tell me.*/

#include<math.h>
#include"expression.h"

/*Expression::Expression(QString s)
{
    expstring=s;
    legal=true;
    result=0;
}*/

double Expression::myBasicCal(double a,double b,int op)
{
    switch(op)
    {
    case 0:
        return a+b;
    case 1:
        return a-b;
    case 2:
        return a*b;
    case 3:
        return a/b;
    case 5:
        return pow(a,b);
    case 6:
        return (int)a%(int)b;
    }
}
int Expression::FunNum(int b,int m)
{
    int i=-1;
    QString functemp=expstring.mid(b+1,m-b-1);
    for( i=8;i<FuncNumber;++i)
    {
        if(functemp==function[i])
            break;
        /*int j=0;
        for( j=b+1;j<m;++j)
        {
            if(function[i][j-b-1]!=expstring[j])
                break;
        }
        if(j>=m)
            break;*/

    }
    if(i>=FuncNumber) return -1;
    return i;
}
    //Expression t(expstring.mid(m+1,e-m-1));
    /*if(!t.LegalAndCal())
    {
        return false;
    }*/
double Expression::FunCal(int funcnum, double x)
{
    funcnum-=8;
    switch(funcnum)
    {
    case 0:
    {
        if(!isRad)
            return sin(x/180*PAI);
        return sin(x);
    }
    case 1:
        if(!isRad)
            return cos(x/180*PAI);
        return cos(x);
    case 2:
    {
        double tResult=x;
        if(!isRad)
            tResult=tResult/180*PAI;
        if(tan(tResult)>1e+15)
            return INFINITY;
        else if(tan(tResult)<-1e+15)
            return -INFINITY;
        else
            return tan(tResult);
    }
    case 3:
        if(!isRad)
            return asin(x)/PAI*180;
        return asin(x);
    case 4:
        if(!isRad)
            return acos(x)/PAI*180;
        return acos(x);
    case 5:
        if(!isRad)
            return atan(x)/PAI*180;
        return atan(x);
    case 6:
        return exp(x);
    case 7:
        return sqrt(x);
    case 8:
        return log(x);
    case 9:
        return log10(x);
    case 10:
        return ceil(x);
    case 11:
        return floor(x);
    case 12:
        return fabs(x);
    case 13:
    {
        if(x<0) return NAN;
        if(x==0) return 1;
        unsigned long long s=1,y=(unsigned long long)x;
        for(;y>=1;--y)
            s*=y;
        return s;
    }
    case 14:
        return log2(x);
    default:
        return NAN;
    }
}

/*bool Expression::ComPri(char a, char b)
{
    int i=0,j=0;
    switch(a)
    {
    case '+':
        i=0;
        break;
    case '-':
        i=1;
        break;
    case '*':
        i=2;
        break;
    case '/':
        i=3;
        break;
    }
    switch(b)
    {
    case '+':
        j=0;
        break;
    case '-':
        j=1;
        break;
    case '*':
        j=2;
        break;
    case '/':
        j=3;
        break;
    }
    if(PRIORITY[i][j]>0)
        return true;
    else
        return false;
}*/

 bool Expression::LegalAndCal()
 {
     //double t=0;
     int op=0;
     for(int i=0;expstring[i]!='\0';++i)
     {
         if(expstring[i].isLetter())
         {
             int begin=i;
             while(expstring[i]!='(')
             {
                 if(expstring[i]=='\0')
                     return false;
                ++i;
             }
             int fnum=FunNum(begin-1,i);
             if(fnum==-1) return false;
             //if(fcresult!=fcresult||fcresult+1==fcresult) return false;
             //sn.push(fcresult);
             sc.push(fnum);
             sc.push(4);
         }
         else
         {
         switch(expstring[i].unicode())
         {
         case '.':
         case '0':
         case '1':
         case '2':
         case '3':
         case '4':
         case '5':
         case '6':
         case '7':
         case '8':
         case '9':
         {
             int b=i;
             while((expstring[i]<='9'&&expstring[i]>='0')||expstring[i]=='.')
             {
                ++i;
             }
             QString numstring=expstring.mid(b,i-b);
             --i;
             if(!MyToDouble(numstring)) return false;
             break;
         }
         case '+':
             if(!opcal(0)) return false;
             break;
         case '-':
             /*if(sn.empty())
             {
                 ++i;
                 int b=i;
                 if(expstring[i]=='(')
                 {
                     while(expstring[i]!=')'&&expstring[i]!='\0')
                     {
                         ++i;
                     }
                     if(expstring[i]=='\0') return false;
                     QString temp=expstring.mid(b+1,i-b-1);
                     Expression et(temp);
                     if(!et.LegalAndCal())
                     {
                         return false;
                     }
                     sn.push(0-et.GetResult());
                 }
                 else
                 {
                    while((expstring[i]<='9'&&expstring[i]>='0')||expstring[i]=='.')
                    {
                        ++i;
                    }
                    QString numstring=expstring.mid(b-1,i-b+1);
                    --i;
                    if(!MyToDouble(numstring)) return false;
                 }
             }
             else
             {*/
             if(i-1<0||expstring[i-1]=='(')
             {
                 sn.push(0);
             }
             if(!opcal(1)) return false;
             break;
         case '*':
             if(!opcal(2)) return false;
             break;
         case '/':
             if(!opcal(3)) return false;
             break;
         case '%':
             if(!opcal(6)) return false;
             break;
         case '^':
             if(!opcal(5)) return false;
             break;
         /*case ' ':
         {
             int begin=i;
             while(expstring[i]!='(')
             {
                 if(expstring[i]=='\0')
                     return false;
                ++i;
             }
             int fnum=FunNum(begin,i);
             if(fnum==-1) return false;
             //if(fcresult!=fcresult||fcresult+1==fcresult) return false;
             //sn.push(fcresult);
             sc.push(fnum);
             sc.push(4);
             break;
         }*/
         case '(':
         {
             /*int b=i;
             while(expstring[i]!=')'&&expstring[i]!='\0')
             {
                 ++i;
             }
             if(expstring[i]=='\0') return false;
             QString temp=expstring.mid(b+1,i-b-1);
             Expression et(temp);
             if(!et.LegalAndCal())
             {
                 return false;
             }
             sn.push(et.GetResult());

             break;*/
             sc.push(4);
             break;
         }
         case ')':
         {
             while(sc.size()>1&&(op=sc.top())!=4)
             {
                 /*if(op>7)
                 {
                     if(sn.empty()) return false;
                     double m=mypop(sn);
                     m=FunCal(op,m);
                     sn.push(m);
                     sc.pop();
                     if(m!=m||m+1==m)
                        return false;
                     continue;
                 }*/
                 if(sn.empty()) return false;
                 double m=mypop(sn);
                 if(sn.empty()) return false;
                 double n=mypop(sn);
                 sn.push(myBasicCal(n,m,op));
                 sc.pop();
             }
             sc.pop();
             if(sc.empty()) return false;
             if((op=sc.top())>7)
             {
                 if(sn.empty()) return false;
                 double m=mypop(sn);
                 m=FunCal(op,m);
                 sn.push(m);
                 sc.pop();
                 if(m!=m||m+1==m)
                    return false;
             }
             break;
         }
         default:
             return false;
         }
         }
     }
     while(sc.size()>1)
     {
         op=sc.top();
         if(op==4)
         {
             sc.pop();
             continue;
         }
         if(op>7)
         {
             if(sn.empty()) return false;
             double m=mypop(sn);
             m=FunCal(op,m);
             sn.push(m);
             sc.pop();
             if(m!=m||m+1==m)
                 return false;
             continue;
         }
         if(sn.empty()) return false;
         double m=mypop(sn);
         if(sn.empty()) return false;
         double n=mypop(sn);
         sn.push(myBasicCal(n,m,op));
         sc.pop();
     }
     //sc.pop();
     if(sn.size()!=1)return false;
     result=mypop(sn);
     return true;
 }

 /*double Expression::GetResult()
 {
     if(result+1==result||result!=result)
         return result;
     return result=myRound(result,15,EPS);
     return result;
 }*/

 void Expression::SetExpression(QString s)
 {
     expstring=s;
     while(!sn.empty())
     {
         sn.pop();
     }
     while(!sc.empty())
     {
         sc.pop();
     }
     sc.push(4);
     result=0;
 }

 bool Expression::MyToDouble(const QString& numstring)
 {
     bool ok=false;
     double b=numstring.toDouble(&ok);
     if(!ok) return false;
     sn.push(b);
     return true;
 }

 bool Expression::opcal(int currentop)
 {
    int op=sc.top();
    if(op>7)
    {
        if(sn.empty()) return false;
        double m=mypop(sn);
        m=FunCal(op,m);
        if(m!=m||m+1==m)
           return false;
        sn.push(m);
        sc.pop();
    }
     for(op=sc.top();PRIORITY[currentop][op]<=0;op=sc.top())
     {
        if(sn.empty()) return false;
        double m=mypop(sn);
        if(sn.empty()) return false;
        double n=mypop(sn);
        sn.push(myBasicCal(n,m,op));
        sc.pop();
     }
     sc.push(currentop);
     return true;
 }
 /*double myRound(double indata,int precision,double eps)
 {
     __int64 magni=1;
     for(int i=0;i<precision;++i)
     {
         magni*=10;
     }
     if(indata>=eps)
         return (__int64)(indata*magni+0.5)/((double)magni);
     else if(indata<=-eps)
         return (__int64)(indata*magni-0.5)/((double)magni);
     else
         return 0;
 }*/
 /**************************************************************************/
 //This version makes the input of "-" more naturally. The negative operator
 //and the subtraction operator are integrated. Now you can use subtraction
 //operator to represent the negative operator.
 /**************************************************************************/





