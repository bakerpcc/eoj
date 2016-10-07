#include<stdio.h>
int ss(int i);
int main()
{int n,j,k,flag1,flag2,max=0,km=0,jm=0;
while(scanf("%d",&n)==1)
	{for(k=2;k<=(n/2);k++)
		{j=n-k;flag1=ss(k);
		if(flag1)
			{flag2=ss(j);
			if(flag2)
				if(k*j>max)
				{max=k*j;km=k;jm=j;}
			}
		}
	printf("%d %d\n",km,jm);
	}
return 0;
}

int ss(int i)
{int j;
if(i<=1) return 0;
if(i==2) return 1;
for(j=2;j<i;j++)
	{if(i%j==0) return 0;
	else if(i!=j+1) continue;
	else return 1;
}
}

