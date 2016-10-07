#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main() {
	char s[100],suoxie[20],*p,*q,word[20]; 
	int i,total,k,j,len;
	while(gets(s)) {
		len = strlen(s);
		for (i = 0; i < len; i++) {
			s[i] = tolower(s[i]);
			if (s[i] == '-' || s[i] == ' ')
				s[i] = '\0';
		}

		p = s;
		for (i = 0; i <= len; i++) {
			if (s[i] == '\0') {
				if((strcmp(p,"the")!=0) && (strcmp(p,"a")!=0)&&(strcmp(p,"an")!=0)&&(strcmp(p,"of")!=0)&&(strcmp(p,"for")!=0)&&(strcmp(p,"and")!=0))
					printf("%c", toupper(*p));

				p = &s[i+1];
			}
		}

		printf("\n"); 
	}
	return 0;
}
