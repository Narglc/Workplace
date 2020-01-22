#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str("narglc");
	const char* ptr = str.c_str();
	cout << *ptr << endl;
	ptr++;
	cout << *ptr << endl;
}
