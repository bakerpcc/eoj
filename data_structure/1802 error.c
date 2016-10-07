#include<stdio.h>
#define MAXN 10

int main()
{
	int k,n,tag;
	int i,j,p,q,r;
	char a[MAXN];
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		scanf("%d",&n);
		scanf(" ");
		for(j=0;j<n;j++)
			scanf("%c",&a[j]);
		//a[j]='\0';
		//for(j=0;j<n;j++)
		//	printf("%c",a[j]);

		tag=0;
		for(p=0;p<n&&tag==0;p++)
			for(q=p+1;q<n&&tag==0;q++){
				if(a[q]<a[p]){
				for(r=q+1;r<n&&tag==0;r++)
					if(a[r]>a[q]) {printf("no\n");tag=1;}
				}
		}
		if(tag==0) printf("yes\n");
	}
	return 0;
}