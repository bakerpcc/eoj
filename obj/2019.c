#include<stdio.h>
int main()
{ int a,n,i;
  while(scanf("%d",&a)!=EOF)
  { 
         a=a<<16|(a>>16&~(~0<<16));
         a=a^~(~0<<16);
         a=a^a<<16;
       for(i=0;i<8;i++)
		     {
              n=a>>(28-i*4)&~(~0<<4);
              if(n<10)printf("%d",n);
              else printf("%c",'A'+n-10);
       }
       printf("\n");
  }
  return 0;
}