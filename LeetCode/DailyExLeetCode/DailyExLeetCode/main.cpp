//
//  main.cpp
//  DailyExLeetCode
//
//  LeetCode 每日打卡
//  Created by Narglc on 2020/3/5.
//  Copyright © 2020 Narglc. All rights reserved.
//

#include "DailyEx.h"
#include "TestHelper.h"

/* 1103 分糖果*/
void distributeCandies_1103()
{
    Solution solution = Solution();
    vector<int> res = solution.distributeCandies(7,4);
    TestHelper::printVector(res);
    res = solution.distributeCandies(10,3);
    TestHelper::printVector(res);
}

void test()
{
    // 生成5个2
    vector<int> arr(5,2);
    TestHelper::printVector(arr);
}

/* 121 买卖股票的最佳时机 */
void maxProfit_121()
{
    vector<int> prices = {}; //{3,3,5,0,0,3,1,4};//{2,1,2,1,0,1,2};//{1,2};//{7,1,5,3,6,4};
    Solution solution = Solution();
    int res = solution.maxProfit(prices);
    cout << "Best Cost: " << res << endl;
    
}


int main(int argc, const char * argv[]) {
    PRINTLINE
    distributeCandies_1103();
    PRINTLINE
    test();
    PRINTLINE
    maxProfit_121();
    return 0;
}
