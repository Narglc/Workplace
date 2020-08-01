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
#include "leetbook.h"
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

void demoreplaceSpaces()
{
    string input = "ds sdfs afs sdfa dfssf asdf              ";//"               ";//"I am good             ";
    cout << "str len: " << input.length() << endl;
    int length = 27; //5;13;
    Solution solution = Solution();
    string out = solution.replaceSpaces(input, length);
    cout << "out:" << out << endl;

}

void demoReverseList()
{
    //1->2->3->4->5->NULL
    ListNode* head = new ListNode(1);
    ListNode* curNode = head;
    curNode->next = new ListNode(2);
//    curNode = curNode->next;
//    curNode->next = new ListNode(3);
//    curNode = curNode->next;
//    curNode->next = new ListNode(4);
//    curNode = curNode->next;
//    curNode->next = new ListNode(5);
    curNode = curNode->next;
    curNode->next = NULL;
    
    curNode = head;
    while(curNode != NULL)
    {
        cout << curNode->val << "->";
        curNode = curNode->next;
    }
    
    Solution solution = Solution();
    ListNode *newHead = solution.reverseList(head);

    cout << "\nnew Result:" << endl;
    curNode = newHead;
    while(curNode != NULL)
    {
        cout << curNode->val << "->";
        curNode = curNode->next;
    }
}

void demoremoveDuplicateNodes()
{
    // [1, 2, 3, 3, 2, 1]
    ListNode* head = new ListNode(1);
    ListNode* curNode = head;
    curNode->next = new ListNode(1);
    curNode = curNode->next;
    curNode->next = new ListNode(2);
    curNode = curNode->next;
    curNode->next = new ListNode(3);
    curNode = curNode->next;
    curNode->next = new ListNode(3);
    curNode = curNode->next;
    curNode->next = new ListNode(2);
    curNode = curNode->next;
    curNode->next = new ListNode(1);
    curNode = curNode->next;
    curNode->next = NULL;
    
    curNode = head;
    while(curNode != NULL)
    {
        cout << curNode->val << "->";
        curNode = curNode->next;
    }
    
    Solution solution = Solution();
    ListNode *newHead = solution.removeDuplicateNodes(head);

    cout << "\nnew Result:" << endl;
    curNode = newHead;
    while(curNode != NULL)
    {
        cout << curNode->val << "->";
        curNode = curNode->next;
    }
    cout << endl;
    
    cout << "test getLinkNodeLength:" << endl;
    cout << solution.getLinkNodeLength(head) << endl;
}

void demorotate()
{
    vector<vector<int>> matrix = {  {1,2,3},
                                    {4,5,6},
                                    {7,8,9}};
    
    Solution solution = Solution();
    solution.rotate(matrix);
    for(auto row:matrix)
    {
        for(auto col:row)
        {
            cout << col << "  ";
        }
        cout << endl;
    }
    cout << endl;

}

void tmpDemo()
{
    string s1 = "waterbottle";
    string s2 = "erbottlewat";
    cout <<  ((s1 + s1).find(s2) != string::npos) << endl;
    
    vector<vector<int>> res;
    res.push_back({1,3,4});
    
    vector<int> a = {1,3,2};
    vector<int> b = {1,3,2,4};
    if(a == b)
        cout << "equal.." << endl;
    
    set<int> test;
    test.insert(3);
    test.insert(1);
    test.insert(2);
    vector<int> testB(test.begin(),test.end());
    for(auto iter:testB)
        cout << iter << " ";
    
}

vector<int> getOrderVector(vector<int> &input)
{
    for(int i = 0; i < 2; i++)
    {
        int minIndex = i;
        int min = input[i];
        for(int j = 1; j < 3; j++)
        {
            if(input[j] < min)
            {
                min  = input[j];
                minIndex = j;
            }
        }
        swap(input[i],input[minIndex]);
    }
    return input;
}

int sumNums(int n) {
    return (n == 1)||(sumNums(n-1)+n);
}

void demomajorityElement()
{
    Solution solu = Solution();
    vector<int> input = {1, 2, 3,3};
    cout << "rst:" << solu.majorityElement(input) << endl;
}

void demodivisorGame()
{
    Solution solu = Solution();
    cout << "1025. 除数博弈:" << solu.divisorGame(10) << endl;
}

void demoexchangeBits()
{
    Solution solu = Solution();
    cout << "面试题 05.07. 配对交换: " << solu.exchangeBits(3) << endl;
}

void demomajorityElement2()
{
    Solution solu = Solution();
    vector<int> input{3,2,3};
    printVec(input);
    cout << "归位:" << solu.majorityElement2(input) << endl;
    printVec(input);
}

void demo_nthUglyNumber()
{
    Solution solu = Solution();
    cout << solu.nthUglyNumber(15) << endl;
}

void demo_subsets()
{
    vector<int> input{1,2,3};
    Solution solu = Solution();
    vector<vector<int>> out = solu.subsets(input);
    
    for(auto first:out)
    {
        cout << "<";
        for(auto each:first)
        {
            cout << each << "-";
        }
        cout << ">" <<endl;
    }
}

void old_demo_test_without_system_study()
{
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

    PRINTLINE
    testVecIter();
    demoAnother();
    demoreplaceSpaces();
    demoReverseList();

    cout << "result: " << endl;
    demoremoveDuplicateNodes();
    PRINTLINE
    demorotate();
    PRINTLINE
    tmpDemo();
    
    PRINTLINE
    vector<int> input = {3,-2,-1};
    vector<int> res = getOrderVector(input);
    for(auto it:res)
        cout << it << ",";
    
    cout << "sumNums:";
    cout << sumNums(3) << endl;

    demomajorityElement();
    demoremoveDuplicateNodes();
    demodivisorGame();
    
    int num = 3;
    cout << ((num&0b00101010101010101010101010101010) >> 1) << endl;
    cout << ((num&0b00010101010101010101010101010101)<<1) << endl;
    cout << (0b01|0b10) <<endl;
    demoexchangeBits();

    demomajorityElement2();
    demo_nthUglyNumber();
    demo_subsets();
}

/* leetbook demo */
void demo_removeDuplicates()
{
    vector<int> nums1{1,2,3,4,5,6};
    vector<int> nums2{0,0,1,1,1,2,2,3,3,4};
    printVec(nums2);
    int last = removeDuplicates(nums2);
    cout << "got num count:" << last << endl;
    printVec(nums2);
    
    // 排序
    vector<int> nums3{5,2,3,1,7,6};
    printVec(nums3);
    sort(nums3.begin(), nums3.end());
    printVec(nums3);
}

void demo_firstUniqChar()
{
    string s = "loveleetcode";
    cout << "first: " << firstUniqChar(s) << endl;
}


void demo_fizzBuzz()
{
    vector<string> res = fizzBuzz(15);
    printVec(res);
}

void demo_hammingWeight()
{
    cout << "bit 1 num: " << hammingWeight(0b00000000000000000000000000001011) << endl;
}

void demo_isValid()
{
    cout << "vaild? " << isValid("}");
    
}

/* leetbook demo with system study*/
void leetbook_ex_with_system_study()
{
    demo_removeDuplicates();
    PRINTLINE
    demo_firstUniqChar();
    PRINTLINE
    demo_fizzBuzz();
    PRINTLINE
    demo_hammingWeight();
    PRINTLINE
    demo_isValid();
}

int main(int argc, const char * argv[]) {
    //old_demo_test_without_system_study();
    
    leetbook_ex_with_system_study();

    return 66;
}
