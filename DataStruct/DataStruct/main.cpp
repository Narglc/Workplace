//
//  main.cpp
//  DataStruct
//
//  Created by Narglc on 2019/5/27.
//  Copyright © 2019 Narglc. All rights reserved.
//

#include <iostream>
#include "dataStruct.hpp"

using namespace std;

#define NEW_LINK_NODE (LinkNode*)malloc(sizeof(LinkNode))
#define LINK_SIZE 6

void CreateLink(LinkNode* &head)
{
    LinkNode* curNode = NEW_LINK_NODE;
    head = curNode;
    curNode->value = 12;
    int TreeSize = 1;
    LinkNode* ptr = NULL;
    while(TreeSize<LINK_SIZE)
    {
        ptr = NEW_LINK_NODE;
        curNode->next = ptr;
        ptr->value = TreeSize+LINK_SIZE;
        curNode = ptr;
        TreeSize++;
    }
    cout << "last Number is " << curNode->value << endl;
}

void PrintLink(LinkNode* head)
{
    int index = 0;
    while(index<LINK_SIZE)
    {
        cout << index << ":" << head->value << endl;
        head = head->next;
        index++;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    LinkNode *head = NULL;
    CreateLink(head);
    PrintLink(head);
    return 0;
}
