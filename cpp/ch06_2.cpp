#include<iostream>

struct book{
  	std::string title;
  	std::string author;
  	unsigned int year;
};

int main(){

	book book1;
	
	std::cout<<"Enter the title of one book:\n";
	std::getline(std::cin,book1.title);

	std::cout<<"Enter the author of one book:\n";
	std::getline(std::cin,book1.author);

	std::cout<<"Enter the year of the book published:\n";
	std::cin>>book1.year;

	std::cout<<"Title: "<<book1.title<<"\nAuthor: "<<book1.author<<"\nPublished Year: "<<book1.year<<std::endl;

	std::cin.ignore(100,'\n');
	std::cout<<"Plz Enter or Return to continue.\n";
	std::cin.get();
	return 0;
	

}
