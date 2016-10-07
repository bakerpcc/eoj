#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct tnode
{
	struct tnode* left;
	struct tnode* right;
	char elem;
};

tnode* Orderings(char* inorder,char *preorder,int len)
{
	if(len==0)
		return NULL;
	tnode* a=(tnode*)malloc(sizeof(tnode));
	a->elem=*preorder;//root node;
	int rootIndex;
	for(rootIndex=0;rootIndex<len;rootIndex++)
	{
		if(inorder[rootIndex]==*preorder)
			break;
	}
	a->left=Orderings(inorder,preorder+1,rootIndex);
	a->right=Orderings(inorder+rootIndex+1,preorder+rootIndex+1,len-rootIndex-1);
	printf("%c",a->elem);
	return a;
}

int main()
{
	char pre[50],in[50];
	scanf("%s %s",pre,in);
	Orderings(in,pre,strlen(in));
	printf("\n");
	return 0;
}