#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void*a,const void*b);

int main()
{
	int n,i,j,k,k1,count;
	char a[100][80+1] = {0}, b[100][80+1] = {0}; 
	char c[27]={"22233344455566677778889999"}; // 这里少了一个9，26个字母+1个'\0'

	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%s",a[i]);

	for(i=0;i<n;i++)//开始对每行进行处理
	{
		k=0;//k为b的列数
		for(j=0;j<strlen(a[i]);j++)
		{
			if (k == 4)
				b[i][k++] = '-';//注意这里的处理方法，就不用下面被注释掉的那种了

			// 这里是小于等于
			if(a[i][j]>='0'&&a[i][j]<='9') 
				b[i][k++]=a[i][j];
			else if(a[i][j]>='A'&&a[i][j]<='Z')
				b[i][k++]=c[a[i][j]-'A'];
			else if(a[i][j]=='-') ;
		}

		b[i][k++] = '\0'; //最好设置串结束符
		
		//for(k1=4;k1<k;k++)
		//	b[i][k1+1]=b[i][k1];//从b[i][4]开始每个向后退1.
		//b[i][4]='-';
	}
	qsort(b,n,80+1,cmp); //或者qsort(b,n,sizeof(char *),cmp);
	
	i = 0;
	while (i < n) {
		printf("%s ", b[i++]);
		count = 1;

		while (i < n && strcmp(b[i], b[i-1]) == 0) {
			count++; i++;
		}

		printf("%d\n", count);
	}

	//for循环，在循环内部不能修改循环变量

	//for(i=0;i<n;i++)
	//{
	//	count=0;//每一次新循环count归零
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
	//return *(char*)a-*(char*)b;注意这个错误
}
