#include <iostream>
using namespace std;
//差分序列 dal
int n,a[200000],dal[200000];

int left(int k)
{
 int i=k-1;
 while(dal[i]<=0 && i>1)
  i--;
 return k-i;
}
int right(int k)
{
 int i=k+1;
 while(dal[i]<=0 && i<=n)
  i++;
 return i-k;
}

int main()
{
 ios::sync_with_stdio(0),cin.tie(0);
 freopen("in.log","r",stdin);
 
 cin>>n;
 int max=0,temp=0;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  dal[i]=a[i]-a[i-1];
 }
 
 //处理前 
 
 cout<<"原序列的差分："; 
 for(int i=1;i<=n;i++)
 {
  cout.width(2);
  cout.setf(ios::right);
  cout<<dal[i]<<" ";
 }
 cout<<endl<<"改变前的序列：";
 int mmm=0;
 for(int i=1;i<=n;i++)
 {
  mmm=mmm+dal[i];
  cout.width(2);
  cout<<mmm<<" ";
 }
 cout<<endl;
 
 
 //处理 
 for(int i=n;i>=1;i--)   //int i = 1;i <=n; i++) 
 {
  if(dal[i]<0)
  {
   int LEFT=left(i),RIGHT=right(i);
   cout << "-------" << endl;
   cout << " i: " << i << " | " << LEFT << "-" << RIGHT << endl;
   if(LEFT>=RIGHT)     //等于是否影响结果 
   {     //选择右边，右边增加 
    //使 i ~ i+RIGHT-1  增加
    dal[i]++;
    dal[i+RIGHT]--; 
    max=max+RIGHT;
   }
   else if(LEFT<RIGHT)
   {     //选择左边，左边减少 
    //使i-LEFT ~ i-1    减少
    dal[i]++;
    dal[i-LEFT]--;  
    max=max+LEFT;
   }   
  }
 } 
 //system("pause");
 cout<<max<<endl;
 

 //以下是输出
 
 cout<<"改变后的差分："; 
 for(int i=1;i<=n;i++)
 {
  cout.width(2);
  cout<<dal[i]<<" ";
 }
 cout<<endl<<"改变后的序列：";
 int sss=0;
 for(int i=1;i<=n;i++)
 {
  cout.width(2);
  sss=sss+dal[i];
  cout<<sss<<" ";
 }
 
 return 0; 
}
 
/*
i=n[全1]|| i=0[全2] 
0(~i 之和==(i)
i+1~n 之和==2*(n-i) 
*/
/* 
魔法

描述
农夫约翰的奶牛场有很多奶牛，奶牛有黑白两种颜色。现在奶牛们排成整齐的一列去参加镇上的游行活动。
约翰希望白色奶牛都排在前面，黑色的奶牛都排在后面。但现在队列中奶牛的颜色是混乱的，并且奶牛们都不愿意改变位置。
幸运的是，约翰有一根魔法棒，每挥舞一次魔法棒就可以改变一头奶牛的颜色。
请问，约翰至少要挥舞多少次魔法棒，才能将队列改成他希望的状态。注意，可以将所有的奶牛都变成白色，或者都变成黑色。

输入格式
第一行一个正整数n，表示奶牛的头数。(1<=n<=200000)。
第二行n个正整数，均为1或2，1表示白色奶牛，2表示黑色奶牛。
输出格式
一个正整数，表示挥舞魔法棒的最少次数。

输入样例
7
2 2 1 1 1 2 1

输出样例
3
提示
可以把1和2号奶牛变成1,7号奶牛变成2，或者全部奶牛变成1，最少需要3次。

finally:
1 1 1 1 1 2 2 -->3
1 1 1 1 1 1 1 -->3

原版：2 2 1 1 1 2 1
前缀：2 4 5 6 7 9 10


*/
