//
//  DailyEx.h
//  DailyExLeetCode
//
//  Created by Narglc on 2020/3/5.
//  Copyright © 2020 Narglc. All rights reserved.
//

#ifndef DailyEx_h
#define DailyEx_h

#include <iostream>
#include <vector>
#include <stack>
#include "TestHelper.h"
#include "LeetCodeStruct.h"
using namespace std;

#define PRINTLINE cout << "-------------------------" << endl;

class Solution {
public:
    int getPeopleNo(int index, int num_people)
    {
        if(index%num_people == 0)
            return num_people - 1;
        else
            return index%num_people - 1;
    }
    
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> arr(num_people,0);
        int index = 1;
        while(candies > 0)
        {
            if(candies > index)
            {
                arr[getPeopleNo(index, num_people)] += index;
                candies = candies - index;
                index++;
            }
            else
            {
                arr[getPeopleNo(index, num_people)] += candies;
                break;
            }
        }
        return arr;
    }
    
#if 0
    vector<vector<int>> findContinuousSequence(int target) {
        
        
        return res;
    }
#endif
    
    
    int maxProfit(vector<int>& prices) {
        // Method 1: 暴力破解
#ifdef METHOD_FIRST
        int max = 0;
        int diff = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            for(int j = i + 1; j < prices.size(); j++)
            {
                diff = prices[j] - prices[i];
                if(diff > 0  && diff > max)
                    max = diff;
            }
        }
        return max;
#elifdefine METHOD_SECOND
        // Method 2: 使用栈
        stack<int> stackStock;
        int max = 0;
        int bottom = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            if(stackStock.size() == 0 || stackStock.top() <= prices[i])
                stackStock.push(prices[i]);
            else if(stackStock.top() > prices[i])
            {
                while(stackStock.size()>0 && stackStock.top() > prices[i])
                    stackStock.pop();
                stackStock.push(prices[i]);
            }
            if(stackStock.size() == 1)
                bottom = stackStock.top();

            if(stackStock.size() >= 2)
            {
                if(stackStock.top() - bottom > max)
                    max = stackStock.top() - bottom;
                if(stackStock.top() - bottom == 0)
                {
                    while(stackStock.size() != 1)
                        stackStock.pop();
                }
            }
        }
//        while(stackStock.size() > 0)
//        {
//            int cur = stackStock.top();
//            cout << cur << " ";
//            stackStock.pop();
//            cout << endl;
//        }
        return max;
#else
        // 方法3:官方答案
        int inf = 1e9;
        int minprice = inf, maxprofit = 0;
        for (int price: prices) {
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(price, minprice);
        }
        cout << "offical..."<< endl;
        return maxprofit;

#endif
    }
    
    //计算深度 需进一步精简！！！ and LeetCode树的读取方法
    int depthOfBinaryTree(TreeNode* root)
    {
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return 0;
        else if(root->left == NULL)
            return depthOfBinaryTree(root->right) + 1;
        else if(root->right == NULL)
            return depthOfBinaryTree(root->left) + 1;
        else
            return max(depthOfBinaryTree(root->right) + 1, depthOfBinaryTree(root->left) + 1);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int left = 0;
        int right = 0;
        if(root == NULL)
            return 0;
        if(root->left != NULL)
            left =  depthOfBinaryTree(root->left) + 1;
        if(root->right != NULL)
            right = depthOfBinaryTree(root->right) + 1;
        return max(left + right, max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
    }
};


#endif /* DailyEx_h */
