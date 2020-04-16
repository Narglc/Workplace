//
//  LeetCodeStruct.h
//  DailyExLeetCode
//
//  Created by Narglc on 2020/3/10.
//  Copyright © 2020 Narglc. All rights reserved.
//

#ifndef LeetCodeStruct_h
#define LeetCodeStruct_h

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

#endif /* LeetCodeStruct_h */
