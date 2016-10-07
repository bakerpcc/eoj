#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *month[19]={"pop", "no", "zip", "zotz", "tzec","xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};

typedef struct{
	int year;
	char month[10];
	int date;
}maya;

int cmp(const void *a,const void *b)
{maya *s1=(maya*)a;maya *s2=(maya*)b;
int r1,r2,i;
for(i=0;i<19;i++)
	{if(strcmp(s1->month,month[i])==0) r1=i;
	if(strcmp(s2->month,month[i])==0) r2=i;
	}
if(s1->year!=s2->year) return s1->year-s2->year;
else if(r1!=r2) return r1-r2;
else return s1->date-s2->date;
}

int main()
{int group,num;
 maya a[10000];
int i,j,k;
scanf("%d",&group);
for(i=0;i<group;i++){
	scanf("%d",&num);
	for(j=0;j<num;j++)
		scanf("%d. %s %d",&a[j].date,a[j].month,&a[j].year);
	qsort(a,num,sizeof(maya),cmp);
	printf("case #%d:\n",i);
	for(j=0;j<num;j++)
		printf("%d. %s %d\n",a[j].date,a[j].month,a[j].year);
	}
return 0;
}