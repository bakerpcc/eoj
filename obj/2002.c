#include<stdio.h>
#include<math.h>
int main()
{int a,b;
while(scanf("%d %d",&a,&b)==2)
{
printf("%.3f\n",sqrt(1.0*(a*a+b*b)));}
return 0;
}