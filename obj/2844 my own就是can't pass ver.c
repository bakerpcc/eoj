#include<stdio.h>
#include<stdlib.h>
#define N 100

int compare1(const void* a,const void* b);
int compare2(const void* a,const void* b);
void sort1(int* s,int n);
void sort2(int* s,int n);

int main()
{char c;
int s[N],n=0,i;
scanf("%c",&c);
while((scanf("%d",&s[n])==1)) n++;
if(c=='A') sort1(s,n);
else if(c='D') sort2(s,n);
printf("%d",s[0]);
for(i=1;i<n;i++)
	if(s[i]!=s[i-1]) printf(" %d",s[i]);
printf("\n");
return 0;
}

int compare1(const void *a,const void *b)
{return *(int*)a-*(int*)b;
}//A£¬ÉýÐò

int compare2(const void *a,const void *b)
{return *(int*)b-*(int*)a;
}//B£¬½µÐò

void sort1(int *s,int n)
{qsort(s,n,sizeof(int),compare1);}

void sort2(int *s,int n)
{qsort(s,n,sizeof(int),compare2);}

