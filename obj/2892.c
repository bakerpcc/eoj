#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{char date[11];
char time[6];
long size;
char name[64];
}file;
int cmp1(const void *a,const void *b)
{file *s1,*s2;
s1=(file*)a;s2=(file*)b;
return strcmp(s1->name,s2->name);
}
int cmp2(const void *a,const void *b)
{file *s1,*s2;
s1=(file*)a;s2=(file*)b;
if (s1->size == s2->size) //如果大小相同，则返回文件名比较结果
    return strcmp(s1->name,s1->name);
else return s1->size-s2->size;
}
int cmp3(const void *a,const void *b)
{file *s1,*s2;
s1=(file*)a;s2=(file*)b;
if(strcmp(s1->date,s2->date)==0)
	{if(strcmp(s1->time,s2->time)==0)
		return strcmp(s1->name,s1->name);
	else return(strcmp(s1->time,s2->time));}
else return strcmp(s1->date,s2->date);
}
int main()
{int group;
file a[100];
int i;
char command[20];
while((scanf("%d",&group)==1)&&(group!=0)){
 for(i=0;i<group;i++)
 scanf("%s %s %d %s ",&a[i].date,&a[i].time,&a[i].size,&a[i].name);
 gets(command);
 if(strcmp(command,"LIST /NAME")==0)
  qsort(a,group,sizeof(file),cmp1);
 if(strcmp(command,"LIST /SIZE")==0)
  qsort(a,group,sizeof(file),cmp2);
 else if(strcmp(command,"LIST /TIME")==0)
  qsort(a,group,sizeof(file),cmp3);

 for(i=0;i<group;i++)
  printf("%s %s %16d %s\n",a[i].date,a[i].time,a[i].size,a[i].name);
 }
return 0;
}