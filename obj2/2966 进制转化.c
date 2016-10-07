#include<stdio.h>

char* trans2(long a)
{char s[7],t[7],*p;
int i=0,j,num;
while(a>0)
	{s[i++]=a%2+'0';a/=2;}
num=i-1;
for(j=0,i=num;i>=0;j++,i--)
	{t[j]=s[i];}
t[j]='\0';
return t;
}

char* trans16(long a)
{char s[7],t[7],*p;
int i=0,j,num;
while(a>0)
	{s[i++]=a%16+'0';a/=16;}
num=i-1;
for(j=0,i=num;i>=0;j++,i--)
	{if(s[i]>'9') t[j]=s[i]-'0'+'a';
	else t[j]=s[i];}
t[j]='\0';
return t;
}

int main()
{int long a,a1,a2;
int group,i,j,k;

char s[500000],t[500000],*p;

scanf("%d",&group);
for(i=0;i<group;i++)
	{	scanf("%ld",&a);

		/*printf("%s %s\n",trans2(a),trans16(a));*/
		if(a==0) {printf("case #%d:\n",i);printf("0 0\n");continue;}

		j=k=0;	
		a1=a2=a;
		while(a1>0) {s[j++]=a1%2+'0';a1=a1/2;}
		while(a2>0) {t[k++]=a2%16+'0';a2=a2/16;/*printf("%c",t[k-1]);*/}
		printf("case #%d:\n",i);
		for(j=j-1;j>=0;j--) printf("%c",s[j]);
		printf(" ");
		for(k=k-1;k>=0;k--) {
			if(t[k]>'9') {/*printf("%c",t[k]);*/t[k]=t[k]-'9'+'A'-1;}
			printf("%c",t[k]);
	}
		printf("\n");
}
return 0;
}