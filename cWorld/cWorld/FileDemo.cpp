//
//  FileDemo.cpp
//  cWorld
//
//  Created by Narglc on 2019/5/30.
//  Copyright © 2019 Narglc. All rights reserved.
//

#include "FileDemo.hpp"

using namespace std;

FileDemo::FileDemo(string fileName)
{
    this->fileName = fileName;
    SetFilePath();
}

string GetBasePath(string fullName)
{
    stringstream strIO;
    string resPath;
    for(auto eachChar:fullName)
    {
        strIO<<eachChar;
        if(eachChar == '/')
        {
            strIO>>resPath;
        }
    }
    return resPath;
    
//    while(!fullName)
//    {
//        if(*fullName == '/')
//        {
//            lastPtr = fullName;
//        }
//        fullName++;
//    }
//    *(++lastPtr) = '\0';

}

void FileDemo::SetFilePath()
{
    //filePath = __FILE__;
    //string fullPath = __FILE__;
    string fullPath = "abcdef/fff";
    filePath = GetBasePath(fullPath);
    //char *curPtr = fullPath;
    //char *bakPtr = fullPath;
}

string FileDemo::GetFilePath()
{
    return filePath;
}

int FileDemo::ReadFileTimes()
{
    ifstream fpIn(fileName);
    if(fpIn)
    {
        string fileContent;
        getline(fpIn, fileContent);
        cout << fileContent << endl;
        fpIn.close();
        return atoi(fileContent.c_str());
    }
    else
    {
        cout<<"File Dose not exist or be removed."<<endl;
        return 0;
    }
}
void FileDemo::WriteFileTimes(int times)
{
    ofstream fpOut(fileName,ofstream::out);
    if(fpOut)
    {
        fpOut<<times;
        fpOut.close();
    }
    else
    {
        cout <<"Write file fail."<<endl;
    }
}
