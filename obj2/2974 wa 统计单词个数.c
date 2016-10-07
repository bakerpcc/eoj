#include<stdio.h>
#include<string.h>

int cmp(char *s)
{if(strcmp(s,"the")==0||strcmp(s,"a")==0||strcmp(s,"an")==0||strcmp(s,"of")==0||strcmp(s,"for")==0||strcmp(s,"and")==0)
return 1;
else return 0;
}

int main()
{
int group,count;
char s[101],*p;
int i;
scanf("%d",&group);
for(i=0;i<group;i++)
	{scanf(" ");
	gets(s);
	strlwr(s);
	/*printf("%s\n",s);*/
	count=0;
	p=strtok(s," ");
	while(p!=NULL)
	{
	if(*p&&(!cmp(p))) count++;
	/*else printf("Ê¡ÂÔ%s",p);*/
	/*printf("%s ",p);*/
	p=strtok(NULL," ");
	}
	printf("case #%d:\n%d\n",i,count);
	}
return 0;
}