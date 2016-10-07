#include<stdio.h>
#include<string.h>
int main()
{char s[1025];
while(scanf("%s",&s)==1)
{printf("%d\n",strlen(s));
}
return 0;
}