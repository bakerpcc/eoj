#include<stdio.h>
int ss(int i);
int main()
{int n,j,k,flag1,flag2,max=0,km=0,jm=0;
while(scanf("%d",&n)==1) {
for(k=2;k<=(n/2);k++) {
// ���k��n-k��������������k*(n-k)��֮ǰ����ĳ˻���������ǰ��
if (ss(k) && ss(n-k) && k*(n-k) > max) {
km = k; jm = n-k; max = km * jm;
}	
}
printf("%d %d\n",km,jm);
}
}
int ss(int i)
{
int j;
if(i<=1) return 0;
if(i==2) return 1;
for(j=2;j<i;j++) {
if(i%j==0) return 0;
}
}