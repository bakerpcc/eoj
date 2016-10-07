#include<stdio.h>
#include<string.h>
int main()
{
char input[100 * 30];
int frequences[26] = { 0 };
int max;
int count = 0,i,i1;
char *p;
gets(input);
for (p = input; *p != '\0'; p++) {
 if (*p != ' ') {
 frequences[*p - 'a']++; //增加该字母的频数
count++;
 }
}

// 找最大频率的字母
max= frequences[0];

for (i = 0; i < 26; i++)
 if (frequences[i] > max) max = frequences[i];

for (i = 0; i < 26; i++) {
 if (frequences[i] == max) 
i1=i+'a';
 break;
}
printf("%c %.2f",i1,(max /(float)count));  //两个整数相除结果会取整而不是浮点数
return 0;
}
