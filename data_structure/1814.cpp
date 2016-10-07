#include<stdio.h>
 
int main()
{
	int tree[1024+1]={0};
	int n,r,i,a,b;
	scanf("%d %d",&n,&r);
	tree[r]=1;
	for(i=1;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		tree[a]+=1; 
		tree[b]+=1; 
	}
	for(i=1;i<n;i++)
		if(tree[i]!=1&&tree[i]!=3)
		{printf("no\n");return 0;}
	printf("yes\n");
	return 0;
}