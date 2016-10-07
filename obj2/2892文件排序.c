#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char order[5];

typedef struct{
char date[11];
char time[6];
long file_size;
char file_name[126];
}file;

int cmp(const void *a,const void *b)
{
	file*s1=(file*)a;file*s2=(file*)b;
	if(strcmp(order,"LIST /NAME")==0)
		return strcmp(s1->file_name,s2->file_name);
	else if(strcmp(order,"LIST /SIZE")==0)
		if(s1->file_size!=s2->file_size)	
			return s1->file_size-s2->file_size;
		else return strcmp(s1->file_name,s2->file_name);
	else if(strcmp(order,"LIST /TIME")==0)
		if(strcmp(s1->date,s2->date)!=0)
			return strcmp(s1->date,s2->date);
		else if(strcmp(s1->time,s2->time)!=0)
			return strcmp(s1->time,s2->time);
		else return strcmp(s1->file_name,s2->file_name);
}

int main()
{	
	int num;
	int i,j,k;
	file a[100];
	while((scanf("%d",&num)==1)&&num!=0)
	{for(i=0;i<num;i++) 
		scanf("%s%s%ld%s",a[i].date,a[i].time,&a[i].file_size,a[i].file_name);
	
	scanf(" ");
	gets(order);
	qsort(a,num,sizeof(file),cmp);

	for(i=0;i<num;i++) 
		printf("%s %s %16ld %s\n",a[i].date,a[i].time,a[i].file_size,a[i].file_name);
	printf("\n");
	}
return 0;
}

