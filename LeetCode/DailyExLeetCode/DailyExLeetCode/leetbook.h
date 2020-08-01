//
//  leetbook.h
//  DailyExLeetCode
//
//  Created by Narglc on 2020/7/31.
//  Copyright © 2020 Narglc. All rights reserved.
//

#ifndef leetbook_h
#define leetbook_h

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <math.h>
#include "TestHelper.h"
#include "LeetCodeStruct.h"
using namespace std;

#define PRINTLINE cout << "-------------------------" << endl;

int removeDuplicates(vector<int>& nums) {
    if(nums.size() == 0)
        return 0;
    int pre = 0;
//    int haveSameFlag = 0;
//    for(size_t i = 1; i < nums.size(); i++)
//    {
//        if(nums[i] == nums[pre])
//        {
//            haveSameFlag = 1;
//            continue;
//        }
//        if(nums[i] != nums[pre])
//        {
//            if(haveSameFlag == 1)
//            {
//                nums[++pre] = nums[i];
//                haveSameFlag = 0;
//            }
//            else
//            {
//                if((i - pre) > 1)
//                    nums[pre+1] = nums[i];
//                pre++;
//            }
//        }
//    }
    
    for(size_t j = 0; j < nums.size(); j++)
    {
        if(nums[j] != nums[pre])
            nums[++pre] = nums[j];
    }
    return ++pre;
}

/* 字符串中的第一个唯一字符 */
int firstUniqChar(string s) {
    int alphaBet[130] = {0};
    for(auto ch:s)
        alphaBet[int(ch)]++;
    
    for(int i = 0; i < s.size(); i++)
        if(alphaBet[int(s[i])] == 1)
            return i;

    return -1;
}

/* Fizz Buzz */
vector<string> fizzBuzz(int n) {
    vector<string> res;
    for(int i = 1; i <= n; i++)
    {
        if(i%15==0)
            res.push_back("FizzBuzz");
        else if(i%5 == 0)
            res.push_back("Buzz");
        else if(i%3 == 0)
            res.push_back("Fizz");
        else
            res.push_back(to_string(i));
    }
    return res;
}

/* 位1的个数 */
int hammingWeight(uint32_t n) {
    int count = 0;
#if 0
    size_t i = 1;
    while(i <= 32)
    {
        if((n&0x01) != 0)
            count++;
        n = n >> 1;
        i++;
    }
    return count;
#else
    while(n != 0)
    {
        count++;
        n = n & (n - 1);
    }
#endif
    return count;
}

bool isValid(string s) {
    if(s.size() == 0)
        return true;
    stack<char> stk;
    for(auto it:s)
    {
        if(stk.size() == 0)
        {
            stk.push(it);
            continue;
        }
        if((it == ')' && stk.top() == '(') ||
           (it == ']' && stk.top() == '[') ||
           (it == '}' && stk.top() == '{'))
        {
            stk.pop();
        }
        else
        {
            stk.push(it);
        }
    }
    if(stk.size())
        return false;
    else
        return true;
}

#endif /* leetbook_h */
