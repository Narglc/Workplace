//#include<iostream>
//#include<string.h>
#include "person.h"

//using namespace std;

void CPerson::show(){
    cout<<"Index: "<<index<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"Salary: "<<salary<<endl;
}

short CPerson::getAge(){
    return age;
}
int CPerson::setAge(short sAge){
    age=sAge;
    return 0;
}
int CPerson::getIndex(){
    return index;
}
int CPerson::setIndex(int iIndex){
    index=iIndex;
    return 0;
}
char* CPerson::getName(){
    return name;
}
int CPerson::setName(char cName[25]){
    strcpy(name,cName);
    return 0;
}

double CPerson::getSalary(){
    return salary;
}
int CPerson::setSalary(double dSalary){
    salary=dSalary;
    return 0;
}
