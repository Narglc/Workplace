#include<iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(long x) {
        if(x<0)
            return false;
        char bit[64] = {0};
        int count =0;
        while(x != 0)
        {
            bit[count++] = x%10;
            x = x/10;
        }
        
        for(int i = 0; i < count; i++)
        {
            printf("%d",bit[i]);
        }
        
        for(int i = 0; i <= count/2; i++)
        {
            if(bit[i] != bit[count-1-i])
                return false;
        }
        return true;
    }
};

int main()
{
	long input = 123456654321;
	cout << (Solution().isPalindrome(input)?"true":"false");

}
