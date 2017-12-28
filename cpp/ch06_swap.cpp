#include<iostream>

void swap(int *A,int *B);

int main(){
	int A=3;
	int B=5;

	std::cout<<"Current Data:\n"<<"A: "<<A<<"\nB: "<<B<<"\n";

	swap(&A,&B);
	
	std::cout<<"\n--------------\n"
	"Changed Data:\n"<<"A: "<<A<<"\nB: "<<B<<"\n";

}

void swap(int *A,int *B){
	int tmp=*A;
	*A=*B;
	*B=tmp;
}
