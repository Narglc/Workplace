//
//  Person.cpp
//  cWorld
//
//  Created by Narglc on 2019/5/29.
//  Copyright © 2019 Narglc. All rights reserved.
//

#include "Person.hpp"
Person::Person(string name, string gender)
{
    this->name = name;
    this->gender = gender;
}
void Person::introduce()
{
    cout << "I'm "<<name<<",and I am a " << gender <<" and " << age << " years old"<<endl;
}

int Person::getAge()
{
    return age;
}

void Person::setAge(int age)
{
    this->age = age;
}
