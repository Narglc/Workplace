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
#include <math.h>
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

    /* 1025. 除数博弈 */
    int theMostBestPlayer(int N) // 返回值表示黑板上的数字
    {
        if(N%2==0)
        {
            if((N/2)%2 == 1)
                return N/2;
        }
        else
        {
            if(N%3==0)
                return N/3*2;
        }
        return N-1;
    }
    
    
    bool divisorGame(int N) {
        int player = 1; //奇数表示爱丽丝
        while(N != 2 && N != 3)
        {
            N = theMostBestPlayer(N);
            player++;
        }
        if(player%2==0 && N == 2)
            return false;
        if(player%2==0 && N == 3)
            return true;
        if(player%2==1 && N == 2)
            return true;
        if(player%2==1 && N == 3)
            return false;
        return false;
        
        
//        if(N == 2)
//            return true;
//        if(N == 3)
//            return false;
//
//        if(N%2==0)
//        {
//            if((N/2)%2 == 1)
//                return divisorGame(N/2);
//            else
//                return divisorGame(N-1);
//        }
//        else
//        {
//            if(N%3==0)
//                return divisorGame(N/3*2);
//            else
//                return divisorGame(N-1);
//        }
    }

    //面试题 05.07. 配对交换
    int exchangeBits(int num) {
        int odd  = ((num&0b00101010101010101010101010101010)>>1);
        int even = ((num&0b00010101010101010101010101010101)<<1);
        cout << "--> odd:" << odd << " even:" << even <<endl;
        int res  = (odd|even);
        return res;
    }
    
    // quickSort
    int quickSort(vector<int>& nums, int left, int right)
    {
        int tmp = nums[left];
        int greatLine = right;
        int i = left+1;
        for(; i <=right; )
        {
            if(i > greatLine)
                break;
            if(nums[i] <= tmp)
                i++;
            else
            {
                swap(nums[i],nums[greatLine]);
                greatLine--;
            }
        }
        swap(nums[left],nums[greatLine]);
        return greatLine;
    }
    
    int majorityElement2(vector<int>& nums) {
#if 0 // 方法一： 使用map记录
        map<int,int> numCount;
        for(auto it:nums)
        {
            numCount[it]++;
        }
        for(auto each:numCount)
        {
            if(each.second > nums.size()/2)
                return each.first;
        }
        return -1;
#else   //todo 待优化，超时
        if(nums.size() == 0)
            return -1;
        // 快排取中间值，并检验
        int mid = nums.size()/2;
        int curSortIndex = 0;
        int left = 0;
        int right = nums.size() - 1;
        curSortIndex = quickSort(nums,left,right);
        while(curSortIndex != mid)
        {
            if(curSortIndex < mid)
                left = curSortIndex+1;
            else
                right = curSortIndex-1;
            curSortIndex = quickSort(nums,left,right);
        }
        int res = nums[mid];
        int count = 0;
        for(auto it:nums)
        {
            if(it == res)
                count++;
        }
        if(count > nums.size()/2)
            return res;
        else
            return -1;
#endif
    }
    
    int nthUglyNumber(int n) {
        if(n == 1)
            return 1;
        map<int,int> uglyNum;
        size_t count = 5;
        uglyNum[2] = 66;
        uglyNum[3] = 66;
        uglyNum[4] = 66;
        uglyNum[5] = 66;
        int from = 6;
        vector<int> res{2,3,5};
        while(count < n)
        {
            if(from%2 ==0 && uglyNum[from/2] == 66)
            {
                uglyNum[from] = 66;
                res.push_back(from);
                from++;
                count++;
                continue;
            }
            if(from%3 ==0 &&uglyNum[from/3] == 66)
            {
                uglyNum[from] = 66;
                res.push_back(from);
                from++;
                count++;
                continue;
            }
            if(from%5 ==0 && uglyNum[from/5] == 66)
            {
                uglyNum[from] = 66;
                res.push_back(from);
                from++;
                count++;
                continue;
            }
            from++;
        }
        return from-1;
    }

    // 面试题 08.04. 幂集
    vector<int> getSubSet(vector<int>& nums, size_t bitNum, int select)
    {
        vector<int> res;
        if(select == 0)
            return res;
        int bitFlag = pow(2,bitNum);
        for(int i = 1; i <= bitNum; i++)
        {
            if((select&(bitFlag>>i)) != 0)
                res.push_back(nums[i-1]);
        }
        return res;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int bitCount = pow(2,nums.size())-1;
        for(int i = 0; i <= bitCount;i++)
        {
            res.push_back(getSubSet(nums, nums.size(), i));
        }
        return res;
    }
};

    /* 剑指 Offer 33. 二叉搜索树的后序遍历序列 */
#define VERSION_ONE 1
#if VERSION_ONE
    /* 优化以后的版本 数组过大时，递归栈过大，导致超时 */
    int isBinarySearchTree(vector<int>& postorder, int begin, int end)  // [begin,end)
    {
        bool flag = false;
        int firstMaxIndex = 0;
        int root = postorder[end-1];
        for(int i = begin; i < end; i++)
        {
            if(!flag)
            {
                if(postorder[i] > root)
                {
                    flag = true;
                    firstMaxIndex = i;
                }
            }
            else
            {
                if(postorder[i] < root)
                    return -1;
            }
        }
        return firstMaxIndex;
    }

    bool verifyPostorder(vector<int>& postorder, int begin, int end)
    {
        if(end - begin < 3)
            return true;
        int flag = isBinarySearchTree(postorder, begin, end);
        if(flag == -1)
        {
            return false;
        }
        return verifyPostorder(postorder, 0, flag) && verifyPostorder(postorder, flag, (int)(end-1));
    }


    bool verifyPostorder(vector<int>& postorder) {
        return verifyPostorder(postorder,0,(int)postorder.size());
    }
#else
    /* 第一个版本 */
    int isBinarySearchTree(vector<int>& postorder)
    {
        bool flag = false;
        int firstMaxIndex = 0;
        int root = postorder[postorder.size()-1];
        for(int i = 0; i < postorder.size(); i++)
        {
            if(!flag)
            {
                if(postorder[i] > root)
                {
                    flag = true;
                    firstMaxIndex = i;
                }
            }
            else
            {
                if(postorder[i] < root)
                    return -1;
            }
        }
        return firstMaxIndex;
    }
    vector<int> getSubArray(vector<int>& postorder, int begin, int end)
    {
        vector<int> res;
        for(size_t i = begin; i < end; i++)
            res.push_back(postorder[i]);
        return res;
    }

    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.size() < 3)
            return true;
        int flag = isBinarySearchTree(postorder);
        if(flag == -1)
        {
            return false;
        }
        vector<int> leftArr  = getSubArray(postorder, 0, flag);
        vector<int> rightArr = getSubArray(postorder, flag, postorder.size()-1);
        return verifyPostorder(leftArr) && verifyPostorder(rightArr);
    }
#endif

    /* 剑指 Offer 62. 圆圈中最后剩下的数字 */
    /* 使用数组模拟，超时；应该使用数学归纳法解决*/
    int lastRemaining(int n, int m) {
        if(n == 1)
            return 0;

        bool* data = new bool[n];
        for(auto i = 0;i < n; i++)
            data[i] = true;

        int curIndex = 0;
        int curLen   = n;

        while(curLen > 1)
        {
            int curNextM = m%curLen;
            for(int j = 1; j <= curNextM; )
            {
                if(curIndex == n)
                    curIndex = 0;
                if(data[curIndex])
                    j++;
                curIndex++;
            }
            data[curIndex-1] = false;
            curLen--;
        }
        cout << "begin:";
        for(auto i = 0;i < n; i++)
            cout << data[i] << "->";
        cout << "end" << endl;
        
        for(auto i = 0;i < n; i++)
            if(data[i])
                return i;
        return -1;
    }

    /* 两数之和 II - 输入有序数组 */
    int binarySearch(vector<int>& numbers, int left, int right, int target)
    {
        int mid = 0;
        while(left <= right)
        {
            mid = left + (right - left);
            if(numbers[mid] == target)
                return mid;
            if(numbers[mid] > target)
                right = mid - 1;
            if(numbers[mid] < target)
                left = mid + 1;
        }
        return -1;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        if(numbers.size() < 2)
            return res;
#if 0   // 方法一：二分查找法，最后一个用例超时
        int secondNumIndex;
        int numToFound;
        for(int i = 0; i < numbers.size() - 1; i++)
        {
            numToFound = target - numbers[i];
            for(int j = i+1; j < numbers.size(); j++)
            {
                if(numbers[j] > numToFound)
                    break;
                secondNumIndex = binarySearch(numbers, j, (int)(numbers.size()-1), numToFound);
                if(secondNumIndex != -1)
                {
                    res.push_back(i+1);
                    res.push_back(secondNumIndex+1);
                    return res;
                }
            }
        }
#else   // 方法二：双指针法
        int left = 0;
        int right = (int)numbers.size() - 1;
        while(left < right)
        {
            if(numbers[left] + numbers[right] == target)
            {
                res.push_back(left+1);
                res.push_back(right+1);
                return res;
            }
            else if(numbers[left] + numbers[right] > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
#endif
        return res;
    }

#endif /* DailyEx_h */
