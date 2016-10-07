#include<stdio.h>
#include<string.h>
int main()
{int n,i;
char a[15];
scanf("%d",&n);
for(i=0;i<n+1;i++)
	{gets(a);
	if(strcmp(a,"E")==0) printf("%s\n","Excellent");
	else if(strcmp(a,"C")==0) printf("%s\n","Cheer");
	else if(strcmp(a,"N")==0) printf("%s\n","Nice");
	else if(strcmp(a,"U")==0) printf("%s\n","Ultimate");
	else if(strcmp(a,"Impossible")==0) printf("%s\n","I'm possible");
	else if(strcmp(a,"ACM")==0) printf("%s\n","Accept More");
	}
return 0;
}