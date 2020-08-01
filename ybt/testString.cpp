#include<iostream>

using namespace std;

int main()
{
	int in = 123;
	string inStr = to_string(in);
	string part = inStr.substr(0,2);
	int res = atoi(part.c_str());
	cout << ++res << endl;
	cout << part << endl;
	cout << "test:" << endl;
	cout << inStr[1] << endl;
	return 0;
}
