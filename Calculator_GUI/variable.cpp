#include "variable.h"

void Variable:: setName(QString arg1){
    name=arg1;
}
void Variable:: setValue(double arg1){
    value=arg1;
}
QString Variable:: getName(){
    return this->name;
}
double Variable:: getValue(){
    return this->value;
}

QString VariableDao:: toString(double num){
    ostringstream oss;
        oss<<num;
        string s;
       s=oss.str();
       return QString(QString::fromLocal8Bit(s.c_str()));
}

void VariableDao:: addVar(Variable arg1){
    vec.push_back(arg1);
}

void VariableDao:: delVar(){
    if(!vec.empty()){
        vec.pop_back();
    }
}

void VariableDao:: clearVar(){
    vec.clear();
}

QString VariableDao:: displayVar(){
    QString Text;
    vector<Variable>::iterator it;
    for(it=vec.begin();it!=vec.end();it++){
        QString tem=(*it).getName()+"="+toString((*it).getValue())+"\n";
        Text.append(tem);
    }
    return Text;
}

QString VariableDao:: trans(QString s){
    QString exp;
    vector<Variable>::iterator it;
    for(it=vec.begin();it!=vec.end();it++){
        exp=(*it).getName();
        int n=s.count(exp);
        double num=(*it).getValue();
        for(int i=0;i<n;i++){
            int loc=s.indexOf(exp);
            s.replace(loc,exp.size(),toString(num));
        }
    }
    return s;
}

int VariableDao:: findByName(QString s){
    int i;
    for(i=vec.size()-1;i>=0;--i){
        if(s==vec.at(i).getName())
            break;
    }
    return i;
}

void VariableDao::modifyVar(int loc,double n){
    vec.at(loc).setValue(n);
}
