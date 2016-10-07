#include <stdio.h>
#include <string.h>
#include <ctype.h>

int cmp(char *s) {
	char t[100], *p;
	strcpy(t, s);
	p = t;
	while(*s) {
		*p++ = tolower(*s++);
	}
	if((strcmp(t,"the")==0)||(strcmp(t,"a")==0)||(strcmp(t,"an")==0)||(strcmp(t,"of")==0)||(strcmp(t,"for")==0)||(strcmp(t,"and")==0))
		return 1;
	else return 0;
}

int main() {
	char s[100],suoxie[20],*p,word[20]; 
	int i,total,k,j,len;
	while(gets(s)) {
		p = strtok(s, " -");
		while(p!=NULL) {
			if (*p && cmp(p) == 0)
				printf("%c", toupper(*p));
			p = strtok(NULL, " -");
		} 
		printf("\n"); 
	}
	return 0;
}