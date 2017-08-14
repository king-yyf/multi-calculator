#include<numberchange.h>
#include<cmath>
#include<cstring>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <String>
#include <cstring>
#include <iostream>

string str="";
using namespace std;


//void numberchange ::Erase(){
//    sta.erase(sta.end()-1);
//}



//十进制转二进制
 string  numberchange::tenTwo(int n)
{
 if(n==0)
    return "0";
    if(n>0){
    int x=n%2;
    tenTwo(n/2);
      str=str+char(x+'0');
     }
     return str;
}

//十进制转八进制
 string numberchange::tenEight(int n)
{
    if(n==0)  //注意特殊情况，本题要求非负数
    return "0";
    if(n>0)
     {
      int x=n%8;
      tenEight(n/8);
      str=str+char(x+'0');
     }

     return str;
}
//十进制转十六进制
char  numberchange::exchange(int n)
{
    if(n<10)
      return n+'0';
    if(n==10)
      return 'A';
    if(n==11)
      return 'B';
    if(n==12)
      return 'C';
    if(n==13)
      return 'D';
    if(n==14)
      return 'E';
    if(n==15)
      return 'F';
}

string  numberchange::tenSixteen(int n)
{
    if(n==0)  //注意特殊情况，要求非负数
    return "0";
    if(n>0)
     {
      int x=n%16;
      tenSixteen(n/16);
      str=str+exchange(x);
     }
     return str;
}


//二进制转十进制
int  numberchange:: twoTen(int n){
    int m=0;
    int i=0;
    while(n!=0){
        if(n%5==0||n%5==1){
         m=m+(n%2)*pow(2,i);
        n=n/10;
        i++;
        }
        else return -1;
    }

     return m;
}
//二进制转八进制
int  numberchange::twoEight(int n){
    int x=twoTen(n);
    int m=0;
    int i=0;
    while(x!=0){
         m=m+(x%8)*pow(10,i);
        x=x/8;
        i++;
    }

     return m;
}
//二进制转十六进制
 string  numberchange::twoSixteen(int n){
    int t=twoTen(n);
    string x="error";
    if(t==-1){
        return x;
    }
    string m=tenSixteen(t);
    return m;
}

 //八进制转十进制
 int  numberchange:: eightTen(int n){
     int m=0;
     int i=0;
     while(n!=0){
         if(n%10<=7){
          m=m+(n%10)*pow(8,i);
         n=n/10;
         i++;
         }
         else return -1;
     }

      return m;
 }
 //八进制转十六进制
 string  numberchange::eightSixteen(int n){
      int t=eightTen(n);
      string x="error";
      if(t==-1){
          return x;
         }
      string m=tenSixteen(t);
         return m;
     }
 //八进制转二进制
 string numberchange::eightTwo(int n){
     int t=eightTen(n);
     string x="error";
     if (t==-1){
         return x;
     }
     string m=tenTwo(t);
      return m;
     }


void numberchange::cleanStr(){
    str=' ';
}
