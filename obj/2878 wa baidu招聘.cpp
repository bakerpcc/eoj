#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#define SLEN 30
#define N 100

int strnumcmp(const void *a, const void *b) {
	char *str1=(char *)a;
	char *str2=(char *)b;
	// s1,s2����str1��str2�з����ֵĲ���
	char *p, s1[SLEN] = {0}, s2[SLEN] = {0};
	// i1, i2����str1��str2�п��ܴ��ڵ�����
	int i1, i2;
	int i;

	p = str1; i = 0; i1 = -1; 
	// whileѭ��ȡstr1�з����ֲ��ֵĴ������浽s1��
	while (*p && !(*p >='0' && *p <= '9')) {
		s1[i++] = *p++;
	}
	// �����ǰ*p�Ǵ�β'\0'�����ʾ���������֣��������ֵ�����浽i1
	if (*p) {
		i1 = 0;
		while (*p)
			i1 = i1 * 10 + *p++;
	}

	p = str2; i = 0;i2 = -1;
	// whileѭ��ȡstr2�з����ֲ��ֵĴ������浽s2��
	while (*p && !(*p >='0' && *p <= '9')) {
		s2[i++] = *p++;
	}
	// �����ǰ*p�Ǵ�β'\0'�����ʾ���������֣��������ֵ�����浽i2
	if (*p) {
		i2 = 0;
		while (*p)
			i2 = i2 * 10 + *p++;
	}

	// ���i1��i2���ǳ�ʼֵ-1�����ʾstr1��str2���Ƿ������ַ�����
	if (i1 == -1 && i2 == -1)
		return strcmp(s1, s2);

	// ������str1��str2��������һ���к�����
	if (i1 == -1) // str1�в�������
		return -1;
	else if (i2 == -1) // str2�в�������
		return 1;
	else // str1��str2�ж�������
		return i1 - i2;
}

int main() {
	char str[N][SLEN];
	int i = 0, n;
	while(scanf("%s", str[i]) == 1) i++;
	n = i;
	qsort(str, i, SLEN, strnumcmp);
	for(i = 0; i < n; i++) printf("%s ", str[i]);

	return 0;
}
