#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void*a,const void*b);

int main()
{
	int n,i,j,k,k1,count;
	char a[100][80+1] = {0}, b[100][80+1] = {0}; 
	char c[27]={"22233344455566677778889999"}; // ��������һ��9��26����ĸ+1��'\0'

	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%s",a[i]);

	for(i=0;i<n;i++)//��ʼ��ÿ�н��д���
	{
		k=0;//kΪb������
		for(j=0;j<strlen(a[i]);j++)
		{
			if (k == 4)
				b[i][k++] = '-';//ע������Ĵ��������Ͳ������汻ע�͵���������

			// ������С�ڵ���
			if(a[i][j]>='0'&&a[i][j]<='9') 
				b[i][k++]=a[i][j];
			else if(a[i][j]>='A'&&a[i][j]<='Z')
				b[i][k++]=c[a[i][j]-'A'];
			else if(a[i][j]=='-') ;
		}

		b[i][k++] = '\0'; //������ô�������
		
		//for(k1=4;k1<k;k++)
		//	b[i][k1+1]=b[i][k1];//��b[i][4]��ʼÿ�������1.
		//b[i][4]='-';
	}
	qsort(b,n,80+1,cmp); //����qsort(b,n,sizeof(char *),cmp);
	
	i = 0;
	while (i < n) {
		printf("%s ", b[i++]);
		count = 1;

		while (i < n && strcmp(b[i], b[i-1]) == 0) {
			count++; i++;
		}

		printf("%d\n", count);
	}

	//forѭ������ѭ���ڲ������޸�ѭ������

	//for(i=0;i<n;i++)
	//{
	//	count=0;//ÿһ����ѭ��count����
	//	while(strcmp(b[i],b[i+1])==0) 
	//	{
	//		count++;i++;
	//	}
	//	printf("%s %d",b[i],count);
	//}
	return 0; 
}

int cmp(const void*a,const void*b)
{
	return strcmp((char *)a, (char *)b);
	//return *(char*)a-*(char*)b;ע���������
}
