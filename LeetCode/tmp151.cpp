#include<iostream>
#include<string>
#include<vector>

using namespace std;
#define LOCAL

#define PRINTLINE cout << "----------------------------------------------" << endl;

class Solution {
public:
    int getNextNotSpace(string &s, int from)
    {
        while(s[from] == ' ' && from < s.size())
            from++;
        return from;
    }

    int getNextStringEnd(string &s, int from)
    {
        while(s[from] != ' ' && from < s.size())
            from++;
        return from; // - 1;
    }

    string reverseWords(string s) {
        vector<string> tmpVec;
        string res;
        if(s.empty())
            return res;
        int index = 0;
        int begin;
        int end;
        while(index < s.size())
        {
            begin = getNextNotSpace(s, index);
            end = getNextStringEnd(s, begin);
	    cout << "cal:[" << begin << "," << end << "]--> " << s.substr(begin, end - begin) << endl; 
            tmpVec.push_back(s.substr(begin, end - begin));  //substr
            index = end;
        }
#ifdef LOCAL
	for(auto it:tmpVec)
	    cout << it << "|" << endl;

	cout <<"s is :" <<  s << endl;
#endif
        for(auto it = tmpVec.rbegin(); it != tmpVec.rend(); it++)
        {
	    if((*it).empty())
		continue;
            res = res + (*it);
            if(it != (tmpVec.rend() - 1))
                res = res + " ";
        }
        return res;
    }

    //面试题 01.01. 判定字符是否唯一
    bool isUnique(string s) {
        char alphaBet[256] = {0};
        for(int index = 0; index < s.size(); index++)
        {
            int alphaNum = int(s[index]);
            if(alphaBet[alphaNum] != 0)
                return false;
            else
                alphaBet[alphaNum] = 1;
        }
        return true;
    }
    
    //面试题 01.03. URL化
    string replaceSpaces(string S, int length) {
	size_t countSpace = 0;
	for(size_t i = 0; i < length; i++)
	{
	    if(S[i] == ' ')
		countSpace++;
	}
	size_t newLength = length + countSpace;
	size_t newIndex = newLength - 1;
	size_t oldIndex = length - 1;
	
	while(newIndex != oldIndex ||  newIndex != 1 || oldIndex != 1)
	{
	    if(S[oldIndex--] == ' ')
	    {
		S[newIndex--] = '0';
		S[newIndex--] = '2';
		S[newIndex--] = '%';
	    }
	    else
	    {
		S[newIndex--] = S[oldIndex--];
	    }
	}
	return S;
    }

};


void demoreplaceSpaces()
{
    Solution solu = Solution();
    string input = "Mr John Smith   |";
    int length = 13;
    string out = solu.replaceSpaces(input, 13);
    cout << "out: " << out << endl;
	
}

int main()
{
    Solution solu;
    string s ="  hello world!  "; //"the sky is blue";
    string out = solu.reverseWords(s);
    cout << "result:--->" << out << endl;
    cout << s.substr(4,3) << endl;
    
    PRINTLINE
    cout << solu.isUnique("abc!") << endl;
    PRINTLINE
    
    string abc = "abc";
    cout << "abc:" << abc << endl;
	   
    PRINTLINE
    demoreplaceSpaces();
	   
    return 0;
}


