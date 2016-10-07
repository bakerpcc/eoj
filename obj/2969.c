#include<stdio.h>
#include<string.h>
int main()
{int group,i,j;
int up,low,space,num,oth;
char s[100+1];
scanf("%d",&group);
for(i=0;i<group;i++){
	scanf(" ");
	gets(s);
	up=low=space=num=oth=0;
	for(j=0;j<strlen(s);j++)
		if(s[j]>='A'&&s[j]<='Z')
			up++;
		else if(s[j]>='a'&&s[j]<='z')
			low++;
		else if(s[j]>='0'&&s[j]<='9')
			num++;
		else if(s[j]==' ')
			space++;
		else oth++;

		printf("case #%d:\n%d %d %d %d %d\n",i,up,low,space,num,oth);
}
return 0;
}
//记住不能用 fflush(stdin);