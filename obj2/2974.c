#include<stdio.h>
#include<string.h>
#include<ctype.h>

int cmp(char*s)
{
	char t[100],*p;
	strcpy(t,s);p=t;
	while(*s){*p++=tolower(*s++);}
	if((strcmp(t,"the")==0)||(strcmp(t,"a")==0)||(strcmp(t,"an")==0)||(strcmp(t,"of")==0)||(strcmp(t,"for")==0)||(strcmp(t,"and")==0))
		return 1;
	else return 0;
}

int main()
{
	int group;
	char s[100+1],*p;
	int i,count;
	scanf("%d",&group);
	for(i=0;i<group;i++)
	{
		scanf(" ");
		count=0;
		gets(s);
		p=strtok(s," ");
		while(p!=NULL)
		{
			if(*p&&cmp(p)==0) count++;
			p=strtok(NULL," ");
		}
	printf("case #%d:\n%d\n",i,count);

	}
return 0;
}