#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 100
void readpoly(char *s, int* co) //��ȡ����ʽ��ÿһ���ϵ���ʹη���
{  while (*s)
   {  int sign=1,a=0,i=0;
      if (*s=='+' ) s++;    //��������+��ʼ
      else if (*s=='-') sign=-1,s++;   //��������-��ʼ
	  //isdigit�����ж��ַ�c�Ƿ�Ϊ����
      while (isdigit(*s)) {  a=a*10+*s-'0'; s++; } //ϵ����ֵ
      if (a==0) a=1; //ϵ��ʡ��ʱ��ʾϵ��Ϊ1
      if (*s!='x') { co[0]=a*sign; return; } else s++; // û�г���xʱ��ʾ0����
      if (*s=='^') s++;
      while (isdigit(*s)) {  i=i*10+*s-'0'; s++; }  //�η���ֵ
      if (i==0) i=1; //ʡ��^������ʱ��ʾ�η�Ϊ1
      co[i]=a*sign;
    }
}
 
void multipy(char *s1,char *s2, int* co) //��������ʽ�ĳ˷�
{  int co1[N]={0},co2[N]={0},i,j;    
   readpoly(s1,co1);   readpoly(s2,co2); //��ȡ����ʽ��ÿ��ϵ���ʹη���
   for (i=0;i<N/2;i++)
     for (j=0;j<N/2;j++)
        co[i+j]+=co1[i]*co2[j];     //x(i��)*x(j��)=x(i+j�Σ�
}
 
int main()
{  char s1[N+1],s2[N+1];
   while(scanf("%s%s",s1,s2)==2)  //��ȡ��������ʽ��ֱ��������
   {  int co[N]={0},out[N],n=0,i;
      multipy(s1,s2,co);
      for (i=0;i<N;i++) if (co[i]) out[n++]=co[i];  //���ֵ��Ϊ0����Щϵ��
      for (i=n-1;i>=0;i--) 
      { printf("%d",out[i]); 
        if (i>0) printf(" "); else printf("\n");
      }
   }
  return 0;
}
