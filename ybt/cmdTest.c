#include<stdio.h>
int test(int a,int b)
{
    return a/b;
}
int main(int argc,char *argv[])
{
	char arr[] = "hello world...";
    int a = 10;
    int b = 0;
    printf("a=%d,b=%d\n",a,b);
	printf("%s",arr);
    test(a,b);
    return 0;
}
