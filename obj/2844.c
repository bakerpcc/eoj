#include <stdio.h>
#include <stdlib.h>

#define N 100

int compare1(const void* a,const void* b)   //升序排序标准
{ return *(int*)a -*(int*)b; }

int compare2(const void* a,const void* b)  //降序排序标准
{ return *(int*)b -*(int*)a; }

int main()
{ char c;  
  int s[N],n=0,i; 

  scanf("%c",&c);                                      //读入排序方式A或D
  while (scanf("%d",&s[n])==1) n++;     //读入待处理数据并获取总的整数个数

  qsort(s,n,sizeof(int),c=='A'?compare1:compare2); //按照排序标准进行排序

  printf("%d",s[0]);            //输出第1个数据（因为n>0，保证至少有一个整数）
  for (i=1;i<n;i++) if (s[i]!=s[i-1]) printf(" %d", s[i]);  //通过与前一个数组元素比较，确定是否是重复数据
  printf("\n");

  return 0;
}
