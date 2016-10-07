#include<stdio.h>
#include<string.h>


char week[7][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};

int main()
{
	char a[60],b[60],c[60],d[60];
	int i,week_day,tag,hour,minute;
	while(scanf("%s",&a)!=EOF)
	{
		scanf("%s",&b);
		scanf("%s",&c);
		scanf("%s",&d);
		week_day=tag=hour=minute=0;
		for(i=0;tag<2;i++)
		{	if(a[i]==b[i]&&(a[i]>='A'&&a[i]<='Z')&&(b[i]>='A'&&a[i]<='Z')&&tag==0)
			{
				week_day=a[i]-'A';
				tag++;
				//printf("%d\n",week_day);
			}
			else if(tag==1&&a[i]==b[i])
			{
				if((a[i]>='0'&&a[i]<='9')&&(b[i]>='0'&&b[i]<='9'))
					hour=a[i]-'0';
				else if((a[i]>='A'&&a[i]<='Z')&&(b[i]>='A'&&b[i]<='Z'))
					hour=a[i]-'A'+10;
				tag++;
			}
		}
		for(i=0,tag=0;tag==0;i++)
			{
				if((c[i]==d[i])&&(((c[i]>='a'&&c[i]<='z')&&(d[i]>='a'&&d[i]<='z'))||(c[i]>='A'&&c[i]<='Z')&&(c[i]>='A'&&c[i]<='Z')))
				{minute=i;tag++;}
			}
			if(minute<10) printf("%s %d:0%d\n",week[week_day],hour,minute);
			else printf("%s %d:%d\n",week[week_day],hour,minute);
	}
	return 0;
}
