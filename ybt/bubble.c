#include <stdio.h>
void maopao(int a[])
{
  //int n = sizeof(a)/sizeof(a[0]);  
  //不能这样用，入参为指针，指针取大小取到的不是整个数组大大小
  int n = 5;
  printf("n=%d\n",n);
  int temp;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (a[j] > a[j + 1])
      {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }
}


int bubuleSort(int a[], int n)
{
  int tmp = 0;
  for(int j=0;j<n-1;j++)
  {
    for(int i = 0; i < n - 1 - j; i++)
    {
      if(a[i]>a[i+1])
      {
        tmp = a[i];
        a[i] = a[i+1];
        a[i+1] = tmp;
      }
    }
  }

}
int main()
{
  int a[5]={4,1,56,12,3};
  int n = sizeof(a)/sizeof(a[0]);
  printf("OUT_n=%d\n",n);
  printf("请输入任意五个整数:");
  //scanf("%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4]);
  maopao(a);
  //bubuleSort(a,5);
  //printf("%d",a[4]);
  for(int i = 0; i < 5; i++)
    printf("%d\t",a[i]);
  return 0;
}