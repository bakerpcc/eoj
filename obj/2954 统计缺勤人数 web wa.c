#include<stdio.h>

#include<stdlib.h>

int main()

{

	 int group;

	 int row,col,i,j,k,count;

	 char *a,*pa;

	 scanf("%d",&group);

	 for(k=0;k<group;k++)

	 {

		 scanf("%d %d",&row,&col);

		 fflush(stdin);

		 count=0;

		 a=(char *)malloc(sizeof(char)*row*col);

		 for(i=0;i<row;i++) {

			 for(j=0;j<col;j++)

				 scanf("%c",&a[i*col+j]);

			 fflush(stdin);

		 }




		 for(pa=a;pa<a+col*row;pa++)

			 if(*pa=='.') count++;

		 printf("case#%d:\n%d\n",k,count);

	 }

	 free(a);

	 return 0;

}