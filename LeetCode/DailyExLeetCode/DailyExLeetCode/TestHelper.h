//
//  TestHelper.h
//  DailyExLeetCode
//
//  Created by Narglc on 2020/3/5.
//  Copyright © 2020 Narglc. All rights reserved.
//

#ifndef TestHelper_h
#define TestHelper_h

using namespace std;

#define PRINTLINE cout << "-------------------------" << endl;

namespace TestHelper {
    
    void printVector(vector<int> vec)
    {
        for(auto each:vec)
            cout << each << " ";
        cout << endl;
    }


}

template<typename T>
void printVec(vector<T> vec)
{
    for(auto each:vec)
        cout << each << " ";
    cout << endl;
}



#endif /* TestHelper_h */
