#include<iostream>
#include<string>

class Pet{
public:
	Pet(std::string theName);
	void play();

protected:
	std::string name;
};

class Cat:public Pet{
public:
	Cat(std::string theName);
	void play();		//覆盖方法
};

Pet::Pet(std::string theName){
	name=theName;
}

void Pet::play(){
	std::cout<<name<<" is playing.\n";
}

Cat::Cat(std::string theName):Pet(theName){
}

void Cat::play(){
	Pet::play();
	std::cout<<name<<" is playing the ball.\n";
}

int main(){
	Cat cat("王猫");
	cat.play();
}
