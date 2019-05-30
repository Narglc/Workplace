//
//  Person.hpp
//  cWorld
//
//  Created by Narglc on 2019/5/29.
//  Copyright © 2019 Narglc. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string name;
    string gender;
    
    Person(string name, string gender);
    void introduce();
    int getAge();
    void setAge(int age);
    
private:
    int age;
    
};

#endif /* Person_hpp */
