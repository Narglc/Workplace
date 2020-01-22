#include<iostream>

//function prototypes,使用函数原型(prototype)定义新函数
//为函数定义原型
void sayHello();
void promptAndWait();

int main(){
	sayHello();
	promptAndWait();
	return 0;
}

void sayHello(){
	std::cout<<"Hello.\n";
}

void promptAndWait(){
	std::cout<<"Press Enter or Return to continue.\n";
	std::cin.get();
}
