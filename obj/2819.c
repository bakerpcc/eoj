#include<math.h>
#include<stdio.h>
#define LEN 1000
int main()
{
	int T,S=0,i,t,p,m,r=0,r1=0,S1=0,a[LEN],b[LEN];
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
	scanf("%d",&a[i]);
	}
	for(i=0;i<T;i++)
	{
		if(a[i]>=3)
		{
			 t=a[i];//t是一开始钱的总数
		     while((int)(a[i]/3)>=1)
		     {
			     r=r+a[i]%3;//r是所有循环下来糖果的余数，留着一起算以便达到换糖果的最大值
			      a[i]=(int)a[i]/3;
			     S=S+a[i];//这种算法是将一开始的a[i]不停地/3（就是先不停地用最初的资本即t换糖），然后将所有/3的结果sum,再所有求余的结果sum
		    //最后一次的a[i]/3小于1了，不能再换糖了，故直接和总的糖纸拼起来换糖。
			 }
			 while((int)(r/3)>=1)
			 {r1=r1+r%3;
			 r=(int)r/3;
			 S1=S1+r;
			 }
		    b[i]=S+(int)((r+r1)/3)+t+S1;//这里的b[i]是真-总数，所有加起来的。
	    }
	else b[i]=a[i];//一开始就小于3的话，有几元钱就只能买几块糖。
	}

	for(i=0;i<T;i++)
	{
		printf("%d\n",b[i]);
	}
	return 0;
}
