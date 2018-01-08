#include<iostream>
#include<string>

class Pet{
public:

	void eat();
	void sleep();
	void setName(std::string theName);

	std::string name;
};

class Cat : public Pet{
public:
	void climb();
};

class Dog : public Pet{
public:
	void bark();
};

void Pet::setName(std::string theName){
	name=theName;
}

void Pet::eat(){
	std::cout<<name<<" eats\n";
}

void Pet::sleep(){
	std::cout<<name<<" sleeps\n";
}

void Cat::climb(){
	std::cout<<name<<" climb a tree\n";
}

void Dog::bark(){
	std::cout<<name<<" goes 'woof-woof'\n";
}

int main(){
	Cat cat;
	Dog dog;

	cat.setName("Garfield");
	dog.setName("Odie");

	cat.sleep();
	cat.eat();
	cat.climb();

	dog.sleep();
	dog.eat();
	dog.bark();
}
