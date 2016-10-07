#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp1(const void*a,const void*b);
int cmp2(const void*a,const void*b);
int cmp3(const void*a,const void*b);

// ��һ���ṹ������ʾһ�еĽṹ��������Щ����Ϊ����Ҫ�õ���ͬ��Ա����Ϣ��Ҳ������qsort�ȽϺ�����ÿ�ζ����
typedef struct {
	char date[11]; // "2012-01-01"����β\0���뱣��
	char time[6]; // "12:00"������5+1
	long size; // �ļ���С
	char filename[64]; // �ļ���������Ҳ�ǿ��Եġ���һ�����ֿ���ռ��2~4���ֽ�
} file_info;

int main2892()
{
	int group,i;
	file_info info[100]; //���100���ļ���Ϣ
	char command[20]={0}; //�����У�LIST /..., 10�ǲ����ģ�����'\0'ҲҪ�����ռ�
	//char a[100][100],order[20];
	while((scanf("%d",&group)==1)&&(group!=0))
	{
		for(i=0;i<group;i++) // ֱ�Ӳ�ֱ��浽�ṹ���Ա��
			scanf("%s%s%d%s ", &info[i].date, &info[i].time, &info[i].size, &info[i].filename);
			//gets(a[i]);
		gets(command);
		if(strcmp(command,"LIST /NAME") == 0)
			qsort(info,group,sizeof(file_info),cmp1);//�Ȱ����ļ���������Ϊsize��time��ͬʱҪ���ļ����������С�
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