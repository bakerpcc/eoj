#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void *a,const void *b)
{
}

int main()
{char ord[27],s[21],t[21][20],*p;
int i,re;
while(gets(ord)){
	i=0;
	gets(s);
	p=s;
	p=strtok(s," ");
	while(p!=NULL){
	strcpy(t[i++],p);
	p=strtok(NULL," ");
	}	
	re=i;
	for(i=0;i<re;i++) printf("%s ",t[i]);
	}
return 0;
}