#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void *a,const void *b)
{
	char*s1=(char*)a;char *s2=(char*)b;
	while(tolower(*s1)==tolower(*s2))
	{
		s1++;s2++;
	}
	return tolower(*s1)-tolower(*s2);
}

int main()
{
	int group,num;
	char s[200][200];
	int i,j,k;
	scanf("%d",&group);
	for(i=0;i<group;i++)
	{
		scanf("%d ",&num);
		for(j=0;j<num;j++)
			gets(s[j]);
		qsort(s,num,200*sizeof(char),cmp);
		printf("case #%d:\n",i);
		for(j=0;j<num;j++)
			printf("%s\n",s[j]);
	}
return 0;
}