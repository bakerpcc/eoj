#include <stdio.h>
#include <stdlib.h>

#define N 100

int compare1(const void* a,const void* b)   //���������׼
{ return *(int*)a -*(int*)b; }

int compare2(const void* a,const void* b)  //���������׼
{ return *(int*)b -*(int*)a; }

int main()
{ char c;  
  int s[N],n=0,i; 

  scanf("%c",&c);                                      //��������ʽA��D
  while (scanf("%d",&s[n])==1) n++;     //������������ݲ���ȡ�ܵ���������

  qsort(s,n,sizeof(int),c=='A'?compare1:compare2); //���������׼��������

  printf("%d",s[0]);            //�����1�����ݣ���Ϊn>0����֤������һ��������
  for (i=1;i<n;i++) if (s[i]!=s[i-1]) printf(" %d", s[i]);  //ͨ����ǰһ������Ԫ�رȽϣ�ȷ���Ƿ����ظ�����
  printf("\n");

  return 0;
}
