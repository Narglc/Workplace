#include<iostream>
#include<vector>
#include<string>
using namespace std;

void demoVectorIntCompare(vector<int> &preVec, vector<int> &curVec)
{
	if(preVec.size() != curVec.size())
		cout << " Not Equal." << endl;
	for(auto preIter:preVec)
	{
		#if 0
		for(auto curIter:curVec)
		{
			cout << " pair: " << preIter << " -- " << curIter << endl;
			if(preIter == curIter)
				break;
		}
		//#else

		#endif
		auto curIter = curVec.begin();
		while(curIter != curVec.end())
		{
			if(curIter == curIter)
				continue;

		}
		//if(curIter == curVec.end())

	}

}

int main()
{
	vector<int> preVec = {1,3,5,7,9};
	vector<int> curVec = {1,3,5,7,9};
	vector<string> preVecStr = {"abc","def","ooo"};
	vector<string> curVecStr = {"abc","dexxxf","ooxo"};
	//demoVectorIntCompare(preVec,curVec);
	if(preVec == curVec)
		cout << "int equal...." << endl;
	if(preVecStr != curVecStr)
		cout << "str equal...." << endl;
	return 0;
}