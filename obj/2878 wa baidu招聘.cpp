#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#define SLEN 30
#define N 100

int strnumcmp(const void *a, const void *b) {
	char *str1=(char *)a;
	char *str2=(char *)b;
	// s1,s2保存str1和str2中非数字的部分
	char *p, s1[SLEN] = {0}, s2[SLEN] = {0};
	// i1, i2保存str1和str2中可能存在的数字
	int i1, i2;
	int i;

	p = str1; i = 0; i1 = -1; 
	// while循环取str1中非数字部分的串，保存到s1中
	while (*p && !(*p >='0' && *p <= '9')) {
		s1[i++] = *p++;
	}
	// 如果当前*p非串尾'\0'，则表示遇到了数字，计算该数值并保存到i1
	if (*p) {
		i1 = 0;
		while (*p)
			i1 = i1 * 10 + *p++;
	}

	p = str2; i = 0;i2 = -1;
	// while循环取str2中非数字部分的串，保存到s2中
	while (*p && !(*p >='0' && *p <= '9')) {
		s2[i++] = *p++;
	}
	// 如果当前*p非串尾'\0'，则表示遇到了数字，计算该数值并保存到i2
	if (*p) {
		i2 = 0;
		while (*p)
			i2 = i2 * 10 + *p++;
	}

	// 如果i1和i2都是初始值-1，则表示str1和str2都是非数字字符串，
	if (i1 == -1 && i2 == -1)
		return strcmp(s1, s2);

	// 到这里str1和str2中至少有一个中含数字
	if (i1 == -1) // str1中不含数字
		return -1;
	else if (i2 == -1) // str2中不含数字
		return 1;
	else // str1和str2中都含数字
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
