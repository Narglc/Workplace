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
#include<cmath>

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

/* 543. 二叉树的直径 */
void diameterOfBinaryTree_543()
{
    //int arr[] = {4,-7,-3,null,null,-9,-3,9,-7,-4,null,6,null,-6,-6,null,null,0,6,5,null,9,null,null,-1,-4,null,null,null,-2};
    TreeNode *root = NULL;
    
    Solution solution = Solution();
    int res = solution.diameterOfBinaryTree(root);
    cout << "maxDiameter : " << res << endl;
}

/* 面试题31. 栈的压入、弹出序列 */
void validateStackSequences_Offer31()
{
    vector<int> pushed = {1,2,3,4,5};
    vector<int> popped = {4,5,3,2,1};
    Solution solution = Solution();
    int res = solution.validateStackSequences(pushed, popped);
    cout << "validate : " << res << endl;
    
    vector<int> pushed2 = {2,1,3}; //{1,2,3,4,5};
    vector<int> popped2 = {1,2};//{4,3,5,1,2};
    int res2 = solution.validateStackSequences(pushed2, popped2);
    cout << "validate : " << res2 << endl;
    
}

void demoQueue()
{
    queue<TreeNode*> queueList;
    TreeNode* curNode = new TreeNode(23);
    queueList.push(curNode);
    TreeNode* curNode2 = new TreeNode(24);
    queueList.push(curNode2);
    queueList.push(NULL);
    TreeNode* curNode3 = new TreeNode(24);
    queueList.push(curNode3);
    
    while(!queueList.empty())
    {
        if(queueList.front() != NULL)
            cout << " ++ " << endl;
        else
            cout << " -- " << endl;
        queueList.pop();
    }
    
    cout << "size:" << queueList.size() << endl;
    
    
}

// Test Demo
void testVecIter()
{
    vector<int> vec = {1,2,3,4,5,6,7,8,9};
    auto it = find(vec.begin(), vec.end(), 1);
    vector<int> left(vec.begin(), it);
    vector<int> right(it+1, vec.end());
    cout << "left:";
    TestHelper::printVector(left);
    cout << "right:";
    TestHelper::printVector(right);
    
    string strA = "abcdefgh";
    cout << strA.substr(2) << endl;
    cout << strA.substr(2) + strA.substr(0,2) << endl;
    cout << strA.length() << endl;
}


void demoAnother()
{
    string testStr = "hEllu";
    Solution solution = Solution();
    size_t res = solution.getIndexFromHead(testStr, 2);
    cout << "index: " << res << "--" << testStr[res] << endl;
    string resStr = solution.reverseVowels(testStr);
    cout << "res:" << resStr << endl;;
    cout << pow(10,3) << endl;
}

int main(int argc, const char * argv[]) {
#if 0
    PRINTLINE
    distributeCandies_1103();
    PRINTLINE
    test();
    PRINTLINE
    maxProfit_121();
    PRINTLINE
    diameterOfBinaryTree_543();
    PRINTLINE
    validateStackSequences_Offer31();
    PRINTLINE
    demoQueue();
#endif
    PRINTLINE
    testVecIter();
    demoAnother();
    return 328;
}
