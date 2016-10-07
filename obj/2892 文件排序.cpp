#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp1(const void*a,const void*b);
int cmp2(const void*a,const void*b);
int cmp3(const void*a,const void*b);

// 用一个结构体来表示一行的结构，更清晰些，因为后面要用到不同成员的信息，也避免了qsort比较函数中每次都拆分
typedef struct {
	char date[11]; // "2012-01-01"，结尾\0必须保留
	char time[6]; // "12:00"，长度5+1
	long size; // 文件大小
	char filename[64]; // 文件名，中文也是可以的。但一个汉字可能占用2~4个字节
} file_info;

int main2892()
{
	int group,i;
	file_info info[100]; //最多100行文件信息
	char command[20]={0}; //命令行：LIST /..., 10是不够的，后面'\0'也要保留空间
	//char a[100][100],order[20];
	while((scanf("%d",&group)==1)&&(group!=0))
	{
		for(i=0;i<group;i++) // 直接拆分保存到结构体成员中
			scanf("%s%s%d%s ", &info[i].date, &info[i].time, &info[i].size, &info[i].filename);
			//gets(a[i]);
		gets(command);
		if(strcmp(command,"LIST /NAME") == 0)
			qsort(info,group,sizeof(file_info),cmp1);//先按照文件名升序，因为size和time相同时要按文件名升序排列。
		if(strcmp(command,"LIST /SIZE") == 0)
			qsort(info,group,sizeof(file_info),cmp2);
		else if(strcmp(command,"LIST /TIME") == 0)
			qsort(info,group,sizeof(file_info),cmp3);
		for(i=0;i<group;i++)
			printf("%s %s %16d %s\n",info[i].date, info[i].time, info[i].size, info[i].filename);
	}
	return 0;
}

int cmp1(const void *a, const void *b)
{
	file_info *s1, *s2;

	s1 = (file_info *)a;
	s2 = (file_info *)b;

	return(strcmp(s1->filename,s1->filename));
}


int cmp2(const void *a, const void *b)
{
	file_info *s1, *s2;

	s1 = (file_info *)a;
	s2 = (file_info *)b;

	return s1->size - s2->size;
}


int cmp3(const void *a, const void *b)
{
	file_info *s1, *s2;
	int n;

	s1 = (file_info *)a;
	s2 = (file_info *)b;

	n = strcmp(s1->date, s2->date);
	if (n == 0)
		return strcmp(s1->time,s2->time);

	return n;
}