//
//  SortTestHelper.h
//  AlgorithmVideo
//
//  Created by Narglc on 2019/7/10.
//  Copyright © 2019 Narglc. All rights reserved.
//

#ifndef SortTestHelper_h
#define SortTestHelper_h

#include<iostream>
#include<cassert>
#include<ctime>

using namespace std;

namespace SortTestHelper {
    // 生成有n个元素的随机数组，每个元素的随机范围为(rangeL,rangeR)
    int* generateRandomArray(int n, int rangeL, int rangeR)
    {
        assert(rangeL <= rangeR);    //assert() 断言需导库 cassert
        int *arr = new int[n];
        srand(time(NULL));          //time() 函数需要导入ctime库
        for(int i = 0; i < n; i++)
        {
            arr[i] = rand() % ( rangeR - rangeL + 1 ) + rangeL;
        }
        
        return arr;
    }
    
    int* copyIntArray(int a[], int n)
    {
        int* arr = new int[n];
//        for(int i = 0; i < n; i++)
//            b[i] = a[i];
        //直接使用copy()函数
        copy(a, a+n, arr);
        return arr;
    }
    
    template<typename T>
    void printArray(T arr[], int num)
    {
        for(int i = 0; i < num; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    template<typename T>
    bool isSorted(T arr[], int n)
    {
        for(int i = 0; i < n - 1; i++)
            if(arr[i] > arr[i+1])
                return false;
        return true;
    }
    
    template<typename T>
    void testSort(string sortName, void(*sort)(T[],int), T arr[], int n)
    {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        assert(isSorted(arr,n));
        cout << sortName << ":" << double(endTime - startTime)/CLOCKS_PER_SEC << " s" << endl;
        return;
    }
    

}

#endif /* SortTestHelper_h */
