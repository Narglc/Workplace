//
//  Student.h
//  AlgorithmVideo
//
//  Created by Narglc on 2019/7/10.
//  Copyright © 2019 Narglc. All rights reserved.
//

#ifndef Student_h
#define Student_h

#include<iostream>
#include<string>

using namespace std;

struct Student{
    string name;
    int score;
    
    bool operator<(const Student &otherStudent)
    {
        //return score < otherStudent.score;
        return score != otherStudent.score? score < otherStudent.score:name<otherStudent.name;
    }
    
    friend ostream& operator<<(ostream &os, const Student &student)
    {
        os<<"Student:"<<student.name<<" "<<student.score<<endl;
        return os;
    }
    
};


#endif /* Student_h */
