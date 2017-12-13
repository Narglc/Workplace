#include<iostream>
#include<string>
#include<fstream>

int main(){
	
	std::string quote,author;
	std::cout<<"请输入一段名言，以#结束:";
	std::getline(std::cin,quote);	//getline() 第三个参数可选,定义停止字符
	
	std::cout<<"请输入作者名:";
	std::getline(std::cin,author);

	std::cout<<"\n";

	std::cout<<"The following quote has been received...\n\n "<<quote<<"\n-"<<author<<"\n\n";

	//把数据输出到文件
	std::ofstream narFile("quotes.out",std::ios::app);
	if(narFile.is_open()){      // 等价于   narFile.good()
		narFile<<quote<<"|"<<author<<"\n";
		narFile.close();
		std::cout<<"这条名言已被记录到文件中!\n";
	}else{
		std::cout<<"The file could not be opened!\n";
		return 1;
	}
	
	/*
	//以下为输入、输出 字段
	std::cout<<"Enter gender:";
	char gender;
	std::cin>>gender;
	std::cout<<"性别:"<<gender<<std::endl;

	std::cin.ignore(100,'\n');

	std::cout<<"Plz input the imformation(忽略空格，仅能接受一个字符):";
	std::string info;
	info=std::cin.get();
	std::cout<<"相关信息:"<<info<<std::endl;
	
	std::cin.ignore(100,'\n');

	std::cout<<"input a number:";
	unsigned short age;
	std::cin>>age;
	
	std::cin.ignore(100,'\n');
	
	std::cout<<"输入一个字符串，遇到空格结束:";
	std::string input;
	std::cin>>input;
	std::cout<<"年龄："<<age<<"字符串："<<input<<std::endl;

	std::cin.ignore(100,'\n');
	*/

}
