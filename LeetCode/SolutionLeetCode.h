#ifndef _SOLUTION_LEETCODE_H_
#define _SOLUTION_LEETCODE_H_

#include<vector>
#include "DataStructLeetCode.h"

using namespace std;

class Solution {
public:

	/* 1. 两数之和 */
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for(int i = 0; i < nums.size()-1; i++)
        {
        	res.push_back(i);
        	for(int j = i + 1; j < nums.size(); j++)
        	{
        		if(target-nums[i] == nums[j])
        		{
        			res.push_back(j);
        			return res;
        		}
        	}
        	res.pop_back();
        }
        return res;
    }

    /* 2. 两数相加 */
    void addOneToHighBit(ListNode* root)
    {
        if(root->val >= 10)
        {
        	root->val = root->val - 10;
        	if(root->next == NULL)
        	{
        		root->next = new ListNode(1);
        	}
        	else
        	{
        		root->next->val = root->next->val + 1;
        		addOneToHighBit(root->next);
        	}
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
        	return l2;
        if(l2 == NULL)
        	return l1;
        l1->val = l1->val + l2->val;
        addOneToHighBit(l1);
        l1->next = addTwoNumbers(l1->next, l2->next);
        return l1;
    }

    /* 2. 寻找两个有序数组的中位数 */
#if 0
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int size_nums1 = nums1.size();
    	int size_nums2 = nums2.size();
    	vector<int> res;
    	int mid = (size_nums1 + size_nums2)/2;
    	int count = 0;
    	while(!nums1.empty()||!nums2.empty())
    	{
    		if(nums1[nums1.size()-1] > nums2[nums2.size()-1]) //.top() > nums2.top())
    		{
    			res.push_back(nums1.pop_back());
    		}
    		else
    		{
    			res.push_back(nums2.pop_back());
    		}
    	}
    	while(!nums1.empty())
    	{
    		res.push_back(nums1.pop_back());
    	}
    	while(!nums2.empty())
    	{
    		res.push_back(nums2.pop_back());
    	}

    	if((size_nums2 + size_nums1)%2 == 0)
    	{

    		return (res[mid]+res[mid-1])/2;
    	}
    	else
    	{
    		return res[mid];
    	}
    }
#endif

	/* 136. 只出现一次的数字 */
    int singleNumber(vector<int>& nums) {
        map<int,int> last;
        for(auto it:nums)
        {
            if(last.find(it) != last.end())
            {
                last.erase(it);
            }
            else
            {
                last[it] = 1;
            }
        }
        return last.begin()->first;
    }


	/* 1313. 解压缩编码列表 */
    vector<int> decompressRLElist(vector<int>& nums) {
    	vector<int> res;
    	if(nums.size()%2 != 0)
    		return res;
    	for(int i = 0 ; i < nums.size(); i+=2)
    	{
    		for(int j = 0; j < nums[i]; j++)
    			res.push_back(nums[i+1]); 
    	}
    	return res;
    }

    /* 1314. 矩阵区域和.  卷积神经网络 */
    int subMatrixBlockSum(vector<vector<int>>& mat, int X_min, int X_max, int Y_min, int Y_max)
    {
    	int sum = 0;
    	for(int i = X_min; i <= X_max; i++)
    	{
    		for(int j = Y_min; j <= Y_max; j++)
    		{
    			sum += mat[i][j];
    		}
    	}
    	return sum;
    }

    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        vector<vector<int>> res;
        if(mat.empty())
        	return res;
        for(int i = 0; i < mat.size(); i++)
        {
        	vector<int> secVec;
        	for(int j = 0; j < mat[0].size(); j++)
        	{
        		int X_min = (i-K <= 0)?0:i-K;
        		int X_max = (i+K >= mat.size()-1)?mat.size()-1:i+K;
        		int Y_min = (j-K <= 0)?0:j-K;
        		int Y_max = (j+K >= mat[0].size()-1)?mat[0].size()-1:j+K;
        		secVec.push_back(subMatrixBlockSum(mat, X_min, X_max, Y_min, Y_max));
        	}
        	res.push_back(secVec);
        }
       	return res;
    }

};

#endif