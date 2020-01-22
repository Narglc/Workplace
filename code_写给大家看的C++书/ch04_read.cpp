#include<iostream>
#include<fstream>
#include<string>
int main(){
	std::string line;
	std::ifstream fileInput("quotes.out");
	
	if(fileInput.is_open()){		//等价于  fileInput.good()
		std::cout<<"The following quotes have been recorded...\n\n";
		while(std::getline(fileInput,line,'|')){
			std::cout<<line<<"\n \t\t- ";
			std::getline(fileInput,line);
			std::cout<<line<<"\n\n";
		}
		fileInput.close();
	}else{
		std::cout<<"The file could not be opened!\n";
		return 1;
	}

}
