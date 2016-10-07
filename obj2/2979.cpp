#include<stdio.h>
#include<stdlib.h>

int main()
{
	int group,a[80][80];
	int mi[]={0,1,0,1,0,-1};
	int mj[]={1,0,-1,0,1,0};
	int m,r,count,k,r1,r2,r3,i,j;
	scanf("%d",&group);

	for(m=0;m<group;m++)
	{
		scanf("%d",&r);
		count = 1;
		a[1][1] = count;
		for (r1 = 2; r1 <= r; r1++) {
			if (r1 % 2 == 0) { // Å¼ÊýÐÐ
				for (r2 = 1; r2 < r1; r2++)
					a[r2][r1] = ++count;
				a[r1][r1] = ++count;
				for (r2 = r1 - 1; r2 > 0; r2--) {
					a[r1][r2] = ++count;
				}
			}
			else {
				for (r2 = 1; r2 < r1; r2++)
					a[r1][r2] = ++count;
				a[r1][r1] = ++count;
				for (r2 = r1 - 1; r2 > 0; r2--) {
					a[r2][r1] = ++count;
				}
			}
		}
		
		printf("case #%d:\n",m);
		for(r1=1;r1<=r;r1++){
			for(r2=1;r2<=r;r2++)
				printf("%d ",a[r1][r2]);
			printf("\n");
		}

	}
	return 0;
}