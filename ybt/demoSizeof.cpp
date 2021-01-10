#include<iostream>

using namespace std;

class A
{
public:
	//char b;
	//virtual void fun(){};
	static int c;
	static int d;
	int e;
	short f;
	long g;
};

int main()
{
	cout << sizeof(A) << endl;
#if 0
	int a = 123;
	cout << sizeof(a) << endl;
	char b = 123;
	cout << sizeof(b) << endl;
	short c = 123;
	cout << sizeof(c) << endl;
	long d = 123;
	cout << sizeof(d) << endl;
#endif
	return 0;
}
