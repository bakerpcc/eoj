#include<stdio.h>
#include<stdlib.h>
int main()
{int total,reminder,swap,n,i;//reminder是剩下的糖果数
int *a,*b;
scanf("%d",&n);
a=(int*)malloc(n*sizeof(int));
b=(int*)malloc(n*sizeof(int));
for(i=0;i<n;i++)
	scanf("%d",&a[i]);
for(i=0;i<n;i++)
	{total=a[i];
	reminder=a[i];
	while(reminder>=3)
		{swap=reminder/3;
		total=total+swap;
		reminder=reminder%3+swap;
		}
	b[i]=total;
	}
for(i=0;i<n;i++)
	printf("\n%d",b[i]);
printf("\n");
return 0;
}