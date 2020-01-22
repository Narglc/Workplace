#include<iostream>

int main(){
	int myvar=23049;
	std::cout<<"The address of myVar is "<<&myvar<<" \n";
	std::cout<<"The address of myVar is "<<(unsigned long)&myvar<<" \n";
	std::cout<<"out!!!\n";

	int myInt=234;
	int *mypointer=&myInt;
	std::cout<<*mypointer<<std::endl;
	std::cout<<&myInt<<std::endl;

	
	std::cout<<"=============\n";
	
	*mypointer=456;
	std::cout<<*mypointer<<std::endl;
	std::cout<<myInt<<std::endl;

}
