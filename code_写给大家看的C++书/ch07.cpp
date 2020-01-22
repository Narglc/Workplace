#include<iostream>

class Car{
public:
	void setName(std::string Name);
	void setYear(int Year);
	void setColor(std::string Color);
	void disp();
	Car(std::string n="NoName",int y=1900,std::string c="yellow");

private:
	std::string name;
	int year;
	std::string color;
};

void Car::setName(std::string Name){
	name=Name;
}

void Car::setYear(int Year){
	year=Year;
}

void Car::setColor(std::string Color){
	color=Color;
}

void Car::disp(){
	std::cout<<"Car Name: "<<name<<"\nCar year: "<<year<<"\nCar color: "<<color<<std::endl;
}

Car::Car(std::string n,int y,std::string c){
	name=n;
	year=y;
	color=c;
};

int main(){
	Car car;
	//car.setName("BMW");
	//car.setYear(1989);
	//car.setColor("Red");

	car.disp();

}
