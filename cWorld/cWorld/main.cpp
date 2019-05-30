//
//  main.c
//  cWorld
//
//  Created by Narglc on 2019/5/5.
//  Copyright © 2019 Narglc. All rights reserved.
//

/*
#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
*/

#include "Person.hpp"
#include "FileDemo.hpp"

#define FILE_NAME_TO_DEMO "test.rec"

void demoPerson()
{
    Person per("Narglc","male");
    per.introduce();
    per.setAge(18);
    cout << "在外部调用私有变量：age --- 年年"<<per.getAge() << "." << endl;
}

int main(int argc, const char * argv[])
{   
    demoPerson();
    
    //读写文件类
    FileDemo fileDemo(FILE_NAME_TO_DEMO);
    cout << "读取文件次数--->";
    int times = fileDemo.ReadFileTimes();
    ++times;
    cout << times << endl;
    fileDemo.WriteFileTimes(times);
    cout << "FilePath:" << fileDemo.GetFilePath()<<endl;
    
    //cout << "Fun:" << __FUNCTION__ <<endl;
    
    return 0;
}
