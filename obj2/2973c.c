#include<stdio.h>
int main()
 
{int group,n,m,p[100],max;
int i,j,k,l;
scanf("%d",&group);
for(i=0;i<group;i++){
	scanf("%d %d",&n,&m);
	max=0;
	for(j=0;j<n;j++) scanf("%d",&p[j]);
	for(j=0;j<n;j++)
		for(k=j+1;k<n;k++)
			for(l=k+1;l<n;l++)
				if((p[j]+p[k]+p[l]<=m)&&(p[j]+p[k]+p[l]>max))
					max=p[j]+p[k]+p[l];
	printf("case #%d:\n%d\n",i,max);
	}
return 0;
}