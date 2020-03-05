//
//  DailyEx.h
//  DailyExLeetCode
//
//  Created by Narglc on 2020/3/5.
//  Copyright © 2020 Narglc. All rights reserved.
//

#ifndef DailyEx_h
#define DailyEx_h

#include <vector>
#include "TestHelper.h"
using namespace std;

#define PRINTLINE cout << "-------------------------" << endl;

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int* arr = new int[num_people];
        int index = 1;
        for(int i = 0; i < num_people; i++)
        {
            arr[i] = 0;
        }
        while(candies > 0)
        {
            if(candies > index)
            {
                arr[index%num_people] += index;
                candies = candies - index;
                index++;
            }
            else
            {
                arr[index%num_people] += candies;
                break;
            }
        }
        vector<int> res;
        for(int i = 1; i < num_people; i++)
        {
            res.push_back(arr[i]);
        }
        res.push_back(arr[0]);
        return res;
    }
    
};


#endif /* DailyEx_h */
