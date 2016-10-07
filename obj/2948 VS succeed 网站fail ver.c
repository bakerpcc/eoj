#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[100][80];
void change(char s[],int a)
{
	int i;
	for(i=0;i<a;i++)
	{
		if(s[i]=='A'||s[i]=='B'||s[i]=='C') s[i]='2';
		else if(s[i]=='D'||s[i]=='E'||s[i]=='F') s[i]='3';
		else if(s[i]=='I'||s[i]=='H'||s[i]=='G') s[i]='4';
		else if(s[i]=='J'||s[i]=='K'||s[i]=='L') s[i]='5';
		else if(s[i]=='O'||s[i]=='N'||s[i]=='M') s[i]='6';
		else if(s[i]=='T'||s[i]=='U'||s[i]=='V') s[i]='8';
		else if(s[i]=='P'||s[i]=='Q'||s[i]=='R'||s[i]=='S') s[i]='7';
		else if(s[i]=='W'||s[i]=='X'||s[i]=='Y'||s[i]=='Z') s[i]='9';
	}
}
int cmp(const void* a,const void* b)
{return (strcmp((char*)a,(char*)b));}
void cpu(char s[][80],int t,int b[])
{
	int i,j=0,k=0;
	for(i=j;i+=j,i<t&&k<t;)
	{
		b[k]=0;
		for(;j<t&&k<t;j++)
		{
			if(s[i]==s[j]) b[k]++;
			else {j=b[k];k++;break;}
		}
	}
}
int main()
{
	int a,t,i,j,k;
	double sum;	
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%s",&s[i]);
		a=strlen(s[i]);
		for(j=0;j<a;j++)
		{
			if(s[i][j]=='-')
			{
				for(k=j;k<a;k++) s[i][k]=s[i][k+1];
			}
		}
		change(s[i],a);
	}
	qsort(s[0],t,80*sizeof(char),cmp);
	for(i=0;i<t;i++)
	{
		k=1;
		while(strcmp(s[i+1],s[i])==0) {k++;i++;}
		for(j=0;j<4;j++) printf("%c",s[i][j]);
		printf("-");
		for(;j<8;j++) printf("%c",s[i][j]);
		printf(" %d\n",k);
	}
	return 0;
}