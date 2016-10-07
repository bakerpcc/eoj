#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int i,j,e;
}triple;

typedef struct{
	triple *data;
	int m,n,c;
}matrix;

matrix * create_matrix(int m,int n,int c)
{
	matrix *a=(matrix*)malloc(sizeof(matrix));
	a->m=m;
	a->n=n;
	a->c=c;
	a->data=(triple*)malloc(c*sizeof(triple));

	return a;
}

void read_matrix(matrix *a)
{
	int i;
	for(i=0;i<a->c;i++)
		scanf("%d%d%d",&a->data[i].i,&a->data[i].j,&a->data[i].e);
}

void print_matrix(matrix *a)
{
	int i;
	for(i=0;i<a->c;i++)
		printf("%d %d %d\n",a->data[i].i,a->data[i].j,a->data[i].e);
}

void transpose(matrix *a,matrix *b)
{
	int p,q,col;
	if(a->c>0)
	{q=0;
	for(col=0;col<a->n;col++)
		for(p=0;p<a->c;p++)
			if(a->data[p].j==col)
			{
				b->data[q].i=a->data[p].j;
				b->data[q].j=a->data[p].i;
				b->data[q].e=a->data[p].e;
				q++;
			}
	}
}

int main()
{
	int m,n,c;
	matrix *a,*b;
	scanf("%d%d%d",&m,&n,&c);
	a=create_matrix(m,n,c);
	b=create_matrix(n,m,c);

	read_matrix(a);
	transpose(a,b);

	print_matrix(b);

	return 0;
}