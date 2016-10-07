#include<stdio.h>
#include<string.h>

int main()
{
	int b[101]={0};
	int i,j,k,a,n,case1,case_count,jinwei,t,record;
	scanf("%d",&case1);
	case_count=0;
	for(;case_count<case1;case_count++)
	{
		scanf("%d %d",&a,&n);
		if(n==0){
			printf("case #%d:\n",case_count);
			printf("1\n");}
		else{memset(b,0,sizeof(b));
		record=0;
		for(i=0,b[0]=1;i<n;i++)
		{
			jinwei=j=0;
			while(b[j]!=0||jinwei!=0||j<=record)
			{
				t=jinwei;
				jinwei=(b[j]*a+jinwei)/10;
				b[j]=(b[j]*a+t)%10;
				j++;
			}
			record=j;

		}
		for(i=100;i>=0;i--)
			if(b[i]!=0) {record=i;break;}
		printf("case #%d:\n",case_count);
		for(i=record;i>=0;i--)
			printf("%d",b[i]);
		printf("\n");
		}
	}
	
	return 0;
}

