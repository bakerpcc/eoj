#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 100
void readpoly(char *s, int* co) //读取多项式的每一项的系数和次方数
{  while (*s)
   {  int sign=1,a=0,i=0;
      if (*s=='+' ) s++;    //处理项以+开始
      else if (*s=='-') sign=-1,s++;   //处理项以-开始
	  //isdigit用于判断字符c是否为数字
      while (isdigit(*s)) {  a=a*10+*s-'0'; s++; } //系数数值
      if (a==0) a=1; //系数省略时表示系数为1
      if (*s!='x') { co[0]=a*sign; return; } else s++; // 没有出现x时表示0次项
      if (*s=='^') s++;
      while (isdigit(*s)) {  i=i*10+*s-'0'; s++; }  //次方数值
      if (i==0) i=1; //省略^及次数时表示次方为1
      co[i]=a*sign;
    }
}
 
void multipy(char *s1,char *s2, int* co) //两个多项式的乘法
{  int co1[N]={0},co2[N]={0},i,j;    
   readpoly(s1,co1);   readpoly(s2,co2); //获取多项式的每项系数和次方数
   for (i=0;i<N/2;i++)
     for (j=0;j<N/2;j++)
        co[i+j]+=co1[i]*co2[j];     //x(i次)*x(j次)=x(i+j次）
}
 
int main()
{  char s1[N+1],s2[N+1];
   while(scanf("%s%s",s1,s2)==2)  //读取两个多项式，直至读不到
   {  int co[N]={0},out[N],n=0,i;
      multipy(s1,s2,co);
      for (i=0;i<N;i++) if (co[i]) out[n++]=co[i];  //输出值不为0的那些系数
      for (i=n-1;i>=0;i--) 
      { printf("%d",out[i]); 
        if (i>0) printf(" "); else printf("\n");
      }
   }
  return 0;
}
