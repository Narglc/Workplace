//
//  main.cpp
//  DailyExLeetCode
//
//  LeetCode 每日打卡
//  Created by Narglc on 2020/3/5.
//  Copyright © 2020 Narglc. All rights reserved.
//

#include <iostream>
#include "DailyEx.h"
#include "TestHelper.h"
void distributeCandies_1103()
{
    Solution solution = Solution();
    vector<int> res = solution.distributeCandies(10,3);
    TestHelper::printVector(res);
    
}



int main(int argc, const char * argv[]) {
    PRINTLINE
    distributeCandies_1103();
    PRINTLINE
    return 0;
}