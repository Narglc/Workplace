//
//  main.cpp
//  AlgorithmVideo
//
//  Created by Narglc on 2019/7/10.
//  Copyright © 2019 Narglc. All rights reserved.
//

#include <iostream>
#include "Student.h"
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void selectionSort(T arr[], int num)
{
    
    for(int i = 0; i < num-1; i++)
    {
        // 寻找[i,n)区间里的最小值
        int minIndex = i;
        for(int j = i+1; j < num; j++)
        {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i],arr[minIndex]);
    }
}

template<typename T>
void insertSort(T arr[], int num)
{
    for(int i = 1; i < num; i++)
    {
        
        int cur = i;                        //可以优化！！！待优化！！！
        for(int j = i-1; j >= 0; j--)
        {
            if(arr[cur]<arr[j])
            {
                swap(arr[cur],arr[j]);
                cur--;
            }
            else
            {
                break;
            }
            
        }
    }
}


int main(int argc, const char * argv[]) {
    
    int intArr[10] = {10,9,8,7,6,5,4,3,2,1};
    insertSort(intArr, 10);
    SortTestHelper::printArray(intArr,10);
    
    float floatArr[5] = {10.34,9.56,9.58,7.1,6.2};
    insertSort(floatArr, 5);
    SortTestHelper::printArray(floatArr,5);

    string str[4] = {"D", "C", "B", "A"};
    insertSort(str, 4);
    SortTestHelper::printArray(str,4);
    
    Student st[4] = {{"D",90},{"C",100},{"B",95},{"A",95}};
    insertSort(st, 4);
    cout << " ";
    SortTestHelper::printArray(st, 4);
    
    // 整理出SorTestHelper类后
    int n = 100000;
    int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
//    selectionSort(arrRandom, n);
//    cout << "自动生成数组排序(" << n << "):" << endl;
//    SortTestHelper:printArray(arrRandom, n);
    SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
    SortTestHelper::testSort("Insert Sort", insertSort, arr2, n);
    
    delete[] arr1;
    delete[] arr2;
    
    return 0;
}
