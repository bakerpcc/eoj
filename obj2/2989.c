#include<stdio.h>
#include<string.h>
int main()
{
	int group;
	char s[10000];
	int num_n,num_a,num_b;
	int one,two,three;
	int i,j,k;
	scanf("%d ",&group);
	for(i=0;i<group;i++)
	{
		//scanf(" ");
		gets(s);
		printf("case #%d:\n",i);
		num_n=num_a=num_b=0;
		for(j=0;j<strlen(s);j++)
		{
			
			if(s[j]=='N') num_n++;
			else if(s[j]=='A') num_a++;
			else if(s[j]=='B') num_b++;
		}
			//printf("%d %d %d",num_n,num_a,num_b);
			if(num_n>num_a)
				{
					if(num_n>num_b) {one=num_n;
					if(num_a>num_b) {two=num_a;three=num_b;}
					else {two=num_b;three=num_a;}
					}
					else {one=num_b;two=num_n;three=num_a;}
				}
			else
				{
					if(num_a>num_b){
						one=num_a;
						if(num_n>num_b){two=num_n;three=num_b;}
						else{two=num_b;three=num_n;}
					}
					else {one=num_b;two=num_a;three=num_n;}
				}
 
			//printf("%d %d %d %d\n",strlen(s),one,two,three);
 
			for(j=0;j<three;j++){printf("NBA");}
			
			if(two==num_a&&one==num_n)
				{
					for(j=0;j<two-three;j++)
						printf("NA");
				}
			else if(two==num_b&&one==num_n)
				{
					for(j=0;j<two-three;j++)
						printf("NB");
				}
			else if(two==num_n&&one==num_b)
				{
					for(j=0;j<two-three;j++)
						printf("NB");
				}
			else if(two==num_a&&one==num_b)
				{
					for(j=0;j<two-three;j++)
						printf("BA");
				}
			else if(two==num_n&&one==num_a)
				{
					for(j=0;j<two-three;j++)
						printf("NA");
				}
			else if(two==num_b&&one==num_a)
				{
					for(j=0;j<two-three;j++)
						printf("BA");
				}
			if(one==num_n)
				for(j=0;j<one-two;j++)
					printf("N");
			else if(one==num_a)
				for(j=0;j<one-two;j++)
					printf("A");
			if(one==num_b)
				for(j=0;j<one-two;j++)
					printf("B");
			printf("\n");
		}
	return 0;
	}