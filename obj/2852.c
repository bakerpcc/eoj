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
 frequences[*p - 'a']++; //���Ӹ���ĸ��Ƶ��
count++;
 }
}

// �����Ƶ�ʵ���ĸ
max= frequences[0];

for (i = 0; i < 26; i++)
 if (frequences[i] > max) max = frequences[i];

for (i = 0; i < 26; i++) {
 if (frequences[i] == max) 
i1=i+'a';
 break;
}
printf("%c %.2f",i1,(max /(float)count));  //����������������ȡ�������Ǹ�����
return 0;
}
