//
//  FileDemo.hpp
//  cWorld
//
//  Created by Narglc on 2019/5/30.
//  Copyright © 2019 Narglc. All rights reserved.
//

#ifndef FileDemo_hpp
#define FileDemo_hpp

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class FileDemo
{
public:
    string fileName;
    FileDemo(string fileName);
    void SetFilePath();
    string GetFilePath();
    int ReadFileTimes();
    void WriteFileTimes(int times);

private:
    string filePath;
};



#endif /* FileDemo_hpp */
