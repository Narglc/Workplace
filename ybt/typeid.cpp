#include <iostream>
#include <assert.h>
using namespace std;

int main()
{
	int myint = 50;
	assert(myint==49);

	cout << typeid(myint).name() << endl;
	cout << typeid(char).name() << endl;

	return 0;
}
