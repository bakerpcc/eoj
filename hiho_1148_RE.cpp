#include<stdio.h>
#include<string.h>

char months[12][20]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"};

int is_year(int n)
{
	return(n%4==0&&n%100!=0)||(n%400==0);
}

int cal(double y,int m,int d)
{
	int sum=y/4+y/400-y/100;
	if(is_year(y)&&(m<2||m==2&&d<29)) sum--;
	return sum;
}

int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		char name1[20],name2[20];
		int d1,d2,m1,m2;
		double y1,y2;
		scanf("%s %d,%f",name1,&d1,&y1);
		scanf("%s %d,%f",name2,&d2,&y2);
		m1=m2=0;
		//printf("%s %s\n",name1,name2);
		for(j=0;j<12;j++)
		{
			if(strcmp(name1,months[j])==0) m1=j+1;
			if(strcmp(name2,months[j])==0) m2=j+1;
			//printf("month:%d %d\n",m1,m2);
		}
		int cnt1=cal(y1,m1,d1);
		int cnt2=cal(y2,m2,d2);
		int cnt=cnt2-cnt1;
		if(is_year(y1)&&m1==2&&d1==29) cnt++;
		printf("Case #%d:%d\n",i,cnt);
	}
}