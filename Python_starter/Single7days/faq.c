#include<stdio.h>

int main()
{
 int i,num;
 _Bool flag=1;
 printf("请输入一个数：\n");
 scanf("%d",&num);
 
 for(i=2;i<num/2;i=i+1)
 {
  if(num%i==0)
  {
   flag=0;
   break;
  }
  }
 
 
if(!flag)
{
 printf("你输入的不是素数!\n");
}
else
{
 printf("你输入的是素数!!\n");
}
 return 0;
 }