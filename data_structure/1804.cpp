#include<stdio.h>
#include<string.h>
#define MAXN 1024
typedef enum{fail,success}status;
typedef enum{false_,true_}boolean;
char s[MAXN],s1[MAXN],s2[MAXN];

int strlen(char *s)
{
	int i;
	for(i=0;s[i]!='\0';i++);
	return i;
}

status strcat(char*s1,char*s2)
{
	int i,j,k;
	if((i=strlen(s1))+(j=strlen(s2))>=MAXN) return (fail);
	for(k=0;k<=j;k++)
		s1[i+k]=s2[k];
	return (success);
}

status strsub(char*s1,int i,int  j,char*s2)
{
	int m,k;
	if(i<0||i>=(m=strlen(s1)))
		return (fail);
	if(j<0||i+j>m)
		return (fail);
	for(k=0;k<j;k++)
		s2[k]=s1[i+k];
	s2[k]='\0';
	return (success);
}

boolean strequ(char*s1,char*s2)
{
	int i=0;
	while(s1[i]==s2[i]&&s1[i]!='\0'&&s2[i]!='\0')
		i++;
	if(s1[i]=='\0'&&s2[i]=='\0')
		return true_;
	else return false_;

}

int main()
{
	int n,i,j;
	char order[7];
	gets(s1);
	scanf("%d",&n);
	scanf(" ");
	while(n>0)
	{
		scanf("%s",order);
		if(strcmp(order,"strcat")==0){
			scanf("%s",s2);
			strcat(s1,s2);
			printf("%s\n",s1);
		}
		else if(strcmp(order,"strsub")==0){
			scanf("%d %d",&i,&j);
			if(strsub(s1,i,j,s2)==success)
				printf("%s\n",s2);
			else 
				printf("fail\n");
		}
		else if(strcmp(order,"strequ")==0){
			scanf("%s",s2);
			if(strequ(s1,s2)==true_)
				printf("yes\n");
			else
				printf("no\n");
		}
		n--;
	}
	return 0;
}
