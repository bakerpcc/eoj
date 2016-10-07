#include<stdio.h>
#include<math.h>
int main()
{double a,b;
while(scanf("%lf %lf",&a,&b)==2)
	printf("%.3lf\n",pow(a,b));//注意精度。double为lf
return 0;
}