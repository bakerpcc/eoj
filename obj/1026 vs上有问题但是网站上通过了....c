#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define g 9.8
int main(){
	int n[17],i=0;
	float h;
	while(scanf("%d",&n[i])==1)
	{
		if(n[i]==0) {exit(0);}
		else
			{h=(n[i]<3)? 5*(n[i]-1)+1.75 : 3*(n[i]-3)+10+1.75;
			printf("%.3f\n",sqrt(2*h/g));
			i++;
			}
	}
	return 0;
}