#ifndef __OFFER_HUNTER__
#define __OFFER_HUNTER__

#include<iostream>
#include<vector>

using namespace std;


#define ARRAY_SIZE 10

#define PRINTLINE cout << "---------------------------" << endl;




/*		Functions		*/
int FindNum(vector<int> inputNumbers);

template<typename T>
void PrintVector(T vec)
{
	for(auto iter:vec)
	{
		cout << iter << " ";
	}
	cout << endl;
}

#endif