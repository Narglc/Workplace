#include<iostream>
#include<string.h>

using namespace std;

//类的声明
class CPerson
{
private:
    int index;
    char name[25];
    short age;
    double salary;


public:
//private:
    void show();
    short getAge();
    int setAge(short sAge);
    int getIndex();
    int setIndex(int iIndex);
    char *getName();
    int setName(char cName[25]);
    double getSalary();
    int setSalary(double dSalary);
};
