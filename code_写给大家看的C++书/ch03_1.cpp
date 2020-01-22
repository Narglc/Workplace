#include<iostream>
#include<cmath>

int main(){
	std::cout<<"testing!!!\n";
	std::cout<<pow(2,3)<<std::endl;

	//声明一个布尔值
	bool approved = true;
	//if语句
	if(approved){
		std::cout<<"is Approved!!!\n";
	}
	
	//else子句
	if(!approved){
		std::cout<<"is Approved!!!\n";
	}else{
		std::cout<<"Nothing is important!!!\n";
	}

	//else if同上
	
	//三元操作符
	std::cout<<((approved)?"are":"are NOT")<<std::endl;
	
	std::cout<<((2==2.0)?"yes":"NO")<<std::endl;

	int year=2017;
	switch(year){
		case 2016:
			std::cout<<"猴年\n";
			break;
		case 2017:
			std::cout<<"鸡年\n";
			break;
		default:	
			std::cout<<"我也不知道是什么年\n";
			break;
	}
	
	int i=27;
	do{
		std::cout<<"即使while后条件语句不成立，也会至少执行一次循环体\n";
	}while(i<27);
	
	int sun=0;
	for(int k=1,l=1;k+l<=100;k++,l++){
		sun+=k*l;
	}
	std::cout<<"Test the sun:"<<sun<<std::endl;
	
	int sum=0;
	for(int j=1;j<=100;j++){
		sum+=j;
	}
	std::cout<<"总和为:"<<sum<<std::endl;

}
