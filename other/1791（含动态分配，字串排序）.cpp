#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void *a,const void *b)
{
	return strcmp(*(char**)a,*(char**)b);
}

char **a;
char word[20];
int len;
char *p;

int main()
{	
	int i,j,k;
	while(gets(word)!=NULL)
	{
		//puts(word);
		len=strlen(word);
		a=(char**)malloc(len*sizeof(char*));

		for(i=0;i<len;i++)
			{a[i]=word+i;
			//puts(a[i]);
		}

		qsort(a,len,sizeof(char*),cmp);

		for(i=0;i<len;i++)
			puts(a[i]);

	}
	return 0;
}