#include<iostream>
#include<cctype>

void promptAndWait();
void convertTemperature(float tempIn,char typeIn);

int main(){
	float temperatureIn;
	char tempTypeIn;

	std::cout<<"Enter a temperature and indicate whether it is in degrees Fahrenheit or Celsius:[##.# C/F]";
	std::cin>>temperatureIn>>tempTypeIn;

	if(
		(toupper(tempTypeIn) == 'C') ||
		(toupper(tempTypeIn) == 'F')
	){
		convertTemperature(temperatureIn,tempTypeIn);
	}else{
		std::cout<<"The calculation could not be made due to invalid input.\n\n";
	}
	promptAndWait();
	return 0;
}

void promptAndWait(){
	std::cin.ignore(100,'\n');
	std::cout<<"Press Enter or Enter to continue.\n";
	std::cin.get();
}

void convertTemperature(float tempIn,char typeIn){
	const unsigned short ADD_SUBTRACT = 32;
	const float RATIO = 5.0/9.0;

	float tempOut;
	char typeOut;

	switch(typeIn){
		case 'C':
		case 'c':
			tempOut = (tempIn/RATIO)+ADD_SUBTRACT;
			typeOut = 'F';
			break;
		case 'F':
		case 'f':
			tempOut = (tempIn-ADD_SUBTRACT)*RATIO;
			typeOut = 'C';
			break;
	}
	
	std::cout<<tempIn<<" degrees "<<typeIn<<" is equal to "<<tempOut<<" degrees "<<typeOut<<".\n\n";
}
