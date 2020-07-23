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
#include <queue>
#include <stack>
#include <set>
#include <map>
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
    
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        if(pushed.size() != popped.size())
            return false;

        stack<int> tmpStack;
        int indexPush = 0;
        for(auto popIter:popped)
        {
            while(indexPush < pushed.size() && popIter != pushed[indexPush])
            {
                if(!tmpStack.empty() && tmpStack.top() == popIter)
                    break;
                tmpStack.push(pushed[indexPush]);
                indexPush++;
            }

            if(indexPush < pushed.size() && popIter == pushed[indexPush])
            {
                indexPush++;
                continue;
            }

            if(!tmpStack.empty() && tmpStack.top() == popIter)
            {
                tmpStack.pop();
                continue;
            }
        }

        if(tmpStack.empty())
            return true;
        else
            return false;
    }
    
    /* 面试题32 - I. 从上到下打印二叉树 */
    vector<int> levelOrder(TreeNode* root)
    {
        vector<int> res;
        if(root == NULL)
            return res;
        queue<TreeNode*> queueTree;
        queueTree.push(root);
        while(!queueTree.empty())
        {
            TreeNode* curNode = queueTree.front();
            if(curNode->left != NULL)
                queueTree.push(curNode->left);
            if(curNode->right != NULL)
                queueTree.push(curNode->right);
            res.push_back(curNode->val);
            queueTree.pop();
        }
        return res;
    }
    
    /* 面试题32 - II. 从上到下打印二叉树 II */
    vector<vector<int>> levelOrder_II(TreeNode* root)
    {
        vector<vector<int>> res;

        vector<int> LevelRes;
        if(root == NULL)
            return res;
        queue<TreeNode*> queueTree;
        queueTree.push(root);
        queueTree.push(NULL);
        while(!queueTree.empty())
        {
            TreeNode* curNode = queueTree.front();
            if(curNode == NULL)
            {
                res.push_back(LevelRes);
                LevelRes.clear();

                if(queueTree.size() == 1)
                    break;
                queueTree.push(NULL);
                queueTree.pop();
                continue;
            }
            if(curNode->left != NULL)
                queueTree.push(curNode->left);
            if(curNode->right != NULL)
                queueTree.push(curNode->right);
            LevelRes.push_back(curNode->val);
            queueTree.pop();
        }
        return res;
    }
    
    /* 面试题07 重建二叉树 */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() != inorder.size() || preorder.empty() || inorder.empty())
            return NULL;
        TreeNode* head = new TreeNode(preorder[0]);
        auto it = find(inorder.begin(), inorder.end(), preorder[0]);
        if(it != inorder.end())
        {
            vector<int> sonLeftInOrder(inorder.begin(), it);
            vector<int> sonRightInOrder(it+1, inorder.end());

            vector<int> sonLeftPreOrder(preorder.begin()+1, preorder.begin()+1+sonLeftInOrder.size());
            vector<int> sonRightPreOrder(preorder.begin()+1+sonLeftInOrder.size(), preorder.end());

            head->left = buildTree(sonLeftPreOrder, sonLeftInOrder);
            head->right = buildTree(sonRightPreOrder, sonRightInOrder);
        }
        else
        {
            return NULL;
        }
        return head;
    }
  
    /* 二叉树到下一个结点 */
    void InOrderTraversal(TreeLinkNode *pNode, vector<TreeLinkNode*> &allNum)
    {
        if(pNode == NULL)
            return;

        InOrderTraversal(pNode->left, allNum);
        allNum.push_back(pNode);
        InOrderTraversal(pNode->right, allNum);
    }
    
    
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        vector<TreeLinkNode*> allNum;
        InOrderTraversal(pNode->next, allNum);
        
        auto it = allNum.begin();
        for(; it != allNum.end()-1 ; )
        {
            if((*it) == pNode)
                return *(++it);
            else
                it++;
        }
        return NULL;
    }
    
    /* 面试题27. 二叉树的镜像 */
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        
        if(root->left != NULL)
            mirrorTree(root->left);
        if(root->right != NULL)
            mirrorTree(root->right);
        
        // TreeNode* tmp = root->left;
        // root->left = root->right;
        // root->right = tmp;
        swap(root->left, root->right);
        
        return root;
    }
    
    /* 345. 反转字符串中的元音字母 */
    size_t getIndexFromHead(string &s, size_t i)
    {
        for(;i < (s.length() - 1) ; i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i'|| s[i] == 'o'|| s[i] == 'u'
             || s[i] == 'A'|| s[i] == 'E'|| s[i] == 'I'|| s[i] == 'O'|| s[i] == 'U')
                return i;
        }
        return i;
    }

    size_t getIndexFromTail(string &s, size_t i)
    {
        for(;i > 0; i--)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i'|| s[i] == 'o'|| s[i] == 'u'
             || s[i] == 'A'|| s[i] == 'E'|| s[i] == 'I'|| s[i] == 'O'|| s[i] == 'U')
                return i;
        }
        return i;
    }

    string reverseVowels(string s) {
        if(s.length() <= 1)
            return s;
        size_t i = 0;
        size_t j = s.size() - 1;
        while(1)
        {
            i = getIndexFromHead(s,i);
            j = getIndexFromTail(s,j);
            if(i > j)
                break;
            swap(s[i++],s[j--]);
        }
        return s;
    }
    
    /* 面试题22. 链表中倒数第k个节点 */
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int num = 0;
        ListNode* pCur = head;
        while(pCur != NULL)
        {
            num++;
            pCur = pCur->next;
        }
        int foundNum = num + 1 - k;
        num = 1;
        while(head != NULL)
        {
            if(num == foundNum)
                return head;
            head = head->next;
            num++;
        }
        return NULL;
    }
    
    /* 面试题 01.03. URL化 */
    string replaceSpaces(string S, int length) {
        size_t countSpace = 0;
        for(size_t i = 0; i < length; i++)
        {
            if(S[i] == ' ')
                countSpace++;
        }

        size_t newLength = length + countSpace*2;
        S[newLength] = '\0';
        size_t newIndex = newLength - 1;

        size_t oldIndex = length - 1;
        while(newIndex != oldIndex)// && newIndex != 0 && oldIndex !=0)
        {
            if(S[oldIndex] == ' ')
            {
                S[newIndex--] = '0';
                S[newIndex--] = '2';
                S[newIndex--] = '%';
            }
            else
            {
                S[newIndex] = S[oldIndex];
                newIndex--;
                
            }
            oldIndex--;
        }
        return S;
    }
    
    /* 面试题24. 反转链表 */
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* preNode = head;
        ListNode* curNode = head->next;
        head->next = NULL;
        ListNode* tmpNode = NULL;
        while(curNode->next != NULL)
        {
            tmpNode = curNode->next;
            curNode->next = preNode;
            preNode = curNode;
            curNode = tmpNode;
        }
        curNode->next = preNode;
        return curNode;
    }
    
    /* 面试题 02.01. 移除重复节点 */
    ListNode* removeDuplicateNodes(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        int hashTable[20001] = { 0 };
        ListNode* pre = head;
        hashTable[pre->val] = 1;
        ListNode* cur = head->next;
        while(cur != NULL)
        {
            if(hashTable[cur->val] == 1)
            {
                cur = cur->next;
                pre->next = cur;
                continue;
            }
            hashTable[cur->val] = 1;
            pre = cur;
            cur = cur->next;
        }
        return head;
    }
    
    /*  面试题 01.07. 旋转矩阵  */
    void rotate(vector<vector<int>>& matrix) {
        size_t rowSize = matrix.size();
        size_t colSize = matrix[0].size();
        vector<vector<int>> res = matrix;
        if(rowSize != colSize)
            return;
        for(int i = 0; i < rowSize; i++)
        {
            for(int j = 0; j < colSize; j++)
            {
//                int tmp = matrix[i][j];
//                matrix[i][j] = matrix[j][colSize- 1 - i];
//                matrix[j][colSize - 1 -i] = tmp;
                //swap(matrix[i][j], matrix[j][colSize-1-i]);
                res[j][colSize-1-i] = matrix[i][j];
            }
        }
        matrix = res;
    }
    
    /* 1290. 二进制链表转整数 */
    int getDecimalValue(ListNode* head) {
        int sum = 0;
        while(head != NULL)
        {
            sum = (sum << 1) + head->val;
            head = head->next;
        }
        return sum;
    }
    
    int majorityElement(vector<int>& nums) {
        map<int,int> numCount;
        for(auto it:nums)
            numCount[it]++;
        map<int,int> countNum;
        for(auto it:numCount)
            countNum.insert(make_pair(it.second,it.first));
        return countNum.rbegin()->second;
    }
    
    /* 剑指 Offer 57. 和为s的两个数字 */
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
#if 1
        //暴力破解
        for(size_t i = 0 ; i < nums.size(); i++)
        {
            int curTarget = target - nums[i];
            for(auto j = i + 1; j < nums.size(); j++)
            {
                if(curTarget == nums[j])
                {
                    res.push_back(curTarget);
                    res.push_back(nums[j]);
                    return res;
                }
            }
        }
        return res;

#else
        map<int,int> numCount;
        for(auto it:nums)
            numCount[it]++;
#endif
    }
    
    
    /* 剑指 Offer 52. 两个链表的第一个公共节点 */
    size_t getLinkNodeLength(ListNode *head)
    {
        size_t length = 0;
        ListNode* cur = head;
        while(cur != nullptr)
        {
            length++;
            cur = cur->next;
        }
        return length;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        size_t lenA = getLinkNodeLength(headA);
        size_t lenB = getLinkNodeLength(headB);
        ListNode *fastPtr,*slowPtr;
        size_t diff;
        if(lenA > lenB)
        {
            fastPtr = headA;
            slowPtr = headB;
            diff = lenA - lenB;
        }
        else
        {
            fastPtr = headB;
            slowPtr = headA;
            diff = lenB - lenA;
        }
        while(diff)
        {
            fastPtr = fastPtr->next;
            diff--;
        }

        while(fastPtr != NULL && slowPtr != NULL && slowPtr != fastPtr)
        {
            fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;
        }
        if(slowPtr == fastPtr)
            return slowPtr;
        return nullptr;
    }

    /*  剑指 Offer 57. 和为s的两个数字
     输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。
     */
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
#if 0         //暴力破解: 对于大数组，时间超限
        for(size_t i = 0 ; i < nums.size(); i++)
        {
            int curTarget = target - nums[i];
            for(auto j = i + 1; j < nums.size(); j++)
            {
                if(curTarget == nums[j])
                {
                    res.push_back(nums[i]);
                    res.push_back(nums[j]);
                    return res;
                }
            }
        }
#else
        // 使用map存储各数值，更方便查找，但忽略了相等的情况
        map<int,int> numCount;
        for(auto it:nums)
            numCount[it]++;
        for(auto it: numCount)
        {
            int curTarget = target - it.first;
            if(numCount.count(curTarget))
            {
                    res.push_back(it.first);
                    res.push_back(curTarget);
                    return res;
            }
        }
#endif
        return res;
    }


};




#endif /* DailyEx_h */
