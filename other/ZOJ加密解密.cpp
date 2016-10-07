#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define N 81

char order[27];

int main()
{
	char a[N],c;
	int i;
	while(gets(order)&&strlen(order)!=0){
	//scanf("%s",order);
	scanf(" ");
	gets(a);
	//c=toupper(order[a[0]-'a']);
	//printf("%c",c);
	//printf("%c\n",a[0]);
	//printf("%c",toupper(order[a[0]-'A']));
	for(i=0;i<strlen(a);i++)
		if(a[i]==' ') printf(" ");
		else
			if(islower(a[i]))
				printf("%c",order[a[i]-'a']);
			else
				printf("%c",toupper(order[a[i]-'A']));
	printf("\n");
	}
	return 0;
}
