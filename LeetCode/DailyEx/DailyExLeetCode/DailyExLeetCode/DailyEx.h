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
#include "TestHelper.h"
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
    
};


#endif /* DailyEx_h */
