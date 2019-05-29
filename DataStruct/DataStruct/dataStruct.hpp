//
//  dataStruct.hpp
//  DataStruct
//
//  Created by Narglc on 2019/5/28.
//  Copyright © 2019 Narglc. All rights reserved.
//

#ifndef dataStruct_hpp
#define dataStruct_hpp

#include <stdio.h>

typedef int ElemType;


typedef struct LinkNode
{
    ElemType value;
    LinkNode *next;
}LinkNode;

#endif /* dataStruct_hpp */
