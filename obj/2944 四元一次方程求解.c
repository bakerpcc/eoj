#include<stdio.h>
int main()
{
	int i,N,n,k;
	int w,x,y,z;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d",&n);
		k=0;
		z=0;
		for(w=0;w<=n/4;w++)
			for(x=0;x<=n/3;x++)
				for(y=0;y<=n/2;y++)
				{
					z=n-4*w-3*x-2*y;
					if(z>=0)  k++;
				}
		printf("%d\n",k);

	}
}
