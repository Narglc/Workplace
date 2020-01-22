#include<iostream>
#include<string>

int main(){
	//同一行代码声明多个同一类型的变量
	unsigned int v1,v2,v3;
	
	//多个变量赋予同样的值
	v1=v2=v3=10;

	//另类赋值方式
	short year(2006);

	//输出
	std::cout<<"Test:"<<year<<" - v1:"<<v1<<std::endl;

	float price=19.95;
	float taxRate=0.05;
	unsigned short quantity=3;
	
	//输出变量值
	std::cout<<"The cost of purchasing "
	<<quantity<<" widget(s) at a price of $"
	<<price<<", with tax,come to $";

	std::cout<<((quantity*price)+((quantity*price)*taxRate))<<".\n";

	std::cout<<"Press Enter or Return to continue.\n";

	//格式化数值
	//使用percision函数来限定被输出的数值其位数最多不能超过几个。
	std::cout.precision(4);
	std::cout<<2.34592<<std::endl;
	
	//使用定点记号(与默认的浮点记号相对立)
	std::cout.setf(std::ios::fixed);
	//显示小数点，不能省略
	std::cout.setf(std::ios::showpoint);
	//精度设置到小数点后面有几位
	std::cout.precision(3);
	std::cout<<2.2359<<std::endl;   //2.346
	std::cout<<30.7164;  //30.716
	
	std::cout<<"\n";
	//char算术运算
	char nar='N';
	char A='a';
	int add=nar+A;
	std::cout<<nar<<"="<<int(nar)<<".\n";
	std::cout<<A<<"="<<int(A)<<".\n";
	std::cout<<add<<".\n";

	std::string narString="qingc";
	std::cout<<narString<<std::endl;
	std::cout<<narString.size(); 

	std::cin.get();

	return 0;
	
}
