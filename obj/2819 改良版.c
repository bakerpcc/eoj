#include<stdio.h>
int main()
{int N,total,reminder,i,a[10],b[10];//total��ʾNԪǮ��һ�����˶����ǡ�reminder��ʾʣ����ֽ��������
int *a,*b;
int BASE=1,DIV=3;//BASEΪ�ǵĵ��ۣ�DIVΪ��������ֽ���ٻ�һ���ǡ�
scanf("%d",&N);
a=(int*)malloc(N*sizeof(int));
b=(int*)malloc(N*sizeof(int));
for(i=0;i<N;i++)
scanf("%d",&a[i]);
for(i=0;i<N;i++)
{total=a[i]/BASE;
reminder=total;
while(reminder>=DIV)
	{int swap=reminder/DIV;//����ѭ���һ���swap���ǡ�
	total=total+swap;
	reminder=reminder%DIV+swap;
	}
b[i]=total;
}
for(i=0;i<N;i++)
printf("\n%d",b[i]);
printf("\n");
return 0;
}

