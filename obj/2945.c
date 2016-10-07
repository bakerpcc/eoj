#include<stdio.h>
int main()
{int n,num[20],i,max=0,maxi[20]={0},j,n1;
char s[20][100];
scanf("%d",&n);
for(i=0;i<n;i++)
 scanf("%s %d",s[i],&num[i]);
for(i=0;i<n;i++)
 if(num[i]>max) max=num[i];
for(i=0,j=0;i<n;i++)
 if(num[i]==max) maxi[j++]=i;
n1=j;
for(j=0;j<n1;j++)
 printf("%s\n",s[maxi[j]]);
return 0;
}