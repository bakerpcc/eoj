#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n, size, row;
	char *a/*a[500][500]*/;
	//char **a;
	int i,j;
	while(scanf("%d",&n)==1) {
		row = 2*n+1;
		size = row * row * sizeof(char);
		a=(char*)malloc(size);
		/*a = (char **)malloc(row * sizeof(char *));
		for (i = 0; i < row; i++) {
			a[i] = (char *)malloc(row * sizeof(char));
			memset(a[i], ' ', row);
		}*/
		memset(a, ' ', size);

		for(i=0;i<n;i++)
			for(j=n-i;j<=n+i;j++)				
				a[i * row + j]='*';/*printf("%c",a[i][j]);*/
				//a[i][j]='*';

		for(i=n,j=0;j<2*n+1;j++) 
			a[i * row + j]='*';
			//a[i][j]='*';

		for(i=n+1;i<2*n+1;i++)
			for(j=i-n;j<=2*n-(i-n);j++)
				a[i * row + j]='*';/*printf("%c",a[i][j]);*/
				//a[i][j]='*';

		for(i=0;i<2*n+1;i++){
			for(j=0;j<2*n+1;j++)
				printf("%c",a[i * row + j]);
				//printf("%c",a[i][j]);
			printf("\n");
		}
	}
	return 0;
}