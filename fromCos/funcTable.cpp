#include<iostream>
#include<map>
using namespace std;

void func1()
{
    cout << "func1" << endl;
}

void func2()
{
    cout << "func2" << endl;
}

void func3()
{
    cout << "func3" << endl;
}

typedef void (*handle)();

const static map<int,handle> funHandleTbl = 
{
    {1,	func1},
    {2,	func2},
    {3,	func3},
};

int main()
{
    for(int i = 1; i <= 3; i++)
    {
        auto it = funHandleTbl.find(i);
	if(it != funHandleTbl.end())
	{
	    (it->second)();
	}
    }
    return 0;
}
