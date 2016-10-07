#include<stdio.h>

int main()
{  char a[10001];
   
   int i,j;
   

   while(gets(a)!=NULL)
   {  i=0;
     while(a[i]!='\0')
		 i++;
		 
	 for(j=i-1;j>=0;j--)
		 printf("%c",a[j]);
	 printf("\n");

   }
} 