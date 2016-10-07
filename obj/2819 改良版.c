#include<stdio.h>
int main()
{int N,total,reminder,i,a[10],b[10];//total表示N元钱第一次买了多少糖。reminder表示剩余糖纸的数量。
int *a,*b;
int BASE=1,DIV=3;//BASE为糖的单价，DIV为多少张糖纸可再换一颗糖。
scanf("%d",&N);
a=(int*)malloc(N*sizeof(int));
b=(int*)malloc(N*sizeof(int));
for(i=0;i<N;i++)
scanf("%d",&a[i]);
for(i=0;i<N;i++)
{total=a[i]/BASE;
reminder=total;
while(reminder>=DIV)
	{int swap=reminder/DIV;//本轮循环兑换了swap颗糖。
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

