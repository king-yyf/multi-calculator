#include<statistics.h>
#include<cmath>
#include<cstring>
bool less1(double a,double b){
    return a<b;
}
bool less2(double a,double b){
    return a>b;
}
void statistics ::AddData(double data){   //添加数据

    sta.push_back(data);
}

void statistics ::Erase(){               //清除上一个数据
    sta.pop_back();
}
QString statistics ::toString(double num){               //清除上一个数据
    ostringstream oss;
        oss<<num;
        string s;
       s=oss.str();
       return QString(QString::fromLocal8Bit(s.c_str()));
}
QString statistics ::Sort(){
    sort(sta.begin(),sta.end(),less1);
    return  renew();

}
QString statistics ::rSort(){
    sort(sta.begin(),sta.end(),less2);
    return  renew();
}
double statistics ::Sum(){   //和
    sum=0.0;
    vector<double>::iterator it;
    for(it=sta.begin();it!=sta.end();it++){
        sum+=*it;
    }
    return sum;
}
double statistics ::DSum(){
    Dsum=0.0;
    vector<double>::iterator it;
    for(it=sta.begin();it!=sta.end();it++)
        Dsum+=(*it)*(*it);
    return Dsum;
}
double statistics ::Average(){
   // ave=0.0;
    sum=this->Sum();
    ave= sum/sta.size();
    return ave;
}
double statistics ::Variance(){
    Dsum=this->DSum();
    ave=this->Average();
    var=Dsum/sta.size()-ave*ave;
    return var;
}
double statistics ::UnVariance(){
   var=this->var;
   if(sta.size()==1){
       Uvar=0.0;
   }else
       Uvar=sta.size()*var/(sta.size()-1);
   return Uvar;
}

double statistics ::Midnum(){
    if(sta.size()==0){
        midnum=0;
    } else{
        int cnt=sta.size()/2;
        sort(sta.begin(),sta.end(),less1);
        if(sta.size()%2==0){
            midnum=(sta.at(cnt-1)+sta.at(cnt))/2;
        }else{
            midnum=sta.at(cnt);
        }
    }
    return midnum;
}

double statistics ::Max_Min(){
    sort(sta.begin(),sta.end(),less1);
    maxmin=sta.back()-sta.front();
    return maxmin;
}

double statistics ::StaVar(){
    Svar=0.0;
   var=this->Variance();
    Svar=sqrt(var);
    return Svar;
}

QString statistics ::renew(){
    QString str;
    double num;
    if(sta.empty()){
        str="0";
    }else{
        vector<double>::iterator it;
        for(it=sta.begin();it!=sta.end();it++){
            num=*it;
            str.append(toString(num));
            str.append(" ");
        }
    }
    return str;
}

void statistics ::empty(){
    sta.clear();
}
