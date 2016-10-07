#include<stdio.h>
int main()
{int n,k,m;
float save,h_price,salary;
int i;
while(scanf("%d %d %d",&n,&k,&m)==3)//n_nianxin,k_fangjia,m_nianxinlv
	{	save=salary=1.0*n;h_price=270.0;
		for(i=1;save<h_price&&(i<=30);i++)
			{salary=salary*(1.0+(1.0*m)/100.0);
			save=save+salary;
			h_price=h_price+h_price*((1.0*k)/100.0);
			/*printf("%f %f\n",save,h_price);*/
			}
		if(i>30) printf("Impossible\n");
		else printf("%d\n",i);
	}
return 0;
}