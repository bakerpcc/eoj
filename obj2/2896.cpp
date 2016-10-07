#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
 
// ��ĸ˳����������ȫ�ֱ���������cmp����ʹ�á�Ĭ����ĸ˳��
char CHARORDER[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 
// qsort����ȽϺ�������ʵֻҪ��qsort�ıȽϺ�����ƺã����ܽ����������⡣���⼴Ϊһ����
int cmp_charorder(const void *a, const void *b) {
	char *pa = (char *)a;
	char *pb = (char *)b;
 
	// pos_a, pos_b�ֱ��¼a��b��ǰ�ַ���CHARORDER��ĸ˳���е����λ�á�
	int pos_a, pos_b;
	
	if (*pa == NULL && *pb == NULL) // ����ָ���Ϊ�գ�a==b
		return 0;
	if (*pa == NULL) // a==NULL,b!=NULL, b��a����a<b 
		return -1;
	else if (*pb == NULL) // b==NULL,a!=NULL, a��b����a>b 
		return 1;
	
	// ��pa��һ���ַ�ת��Ϊ��д��Ȼ����CHARORDER�в��Ҹô�д��ĸ���ڵ�λ�á�
	// strchr��ָ���ַ����в���ĳ���ַ���λ�ã�����ֵ��ָ����ַ���ָ�룬��ȥ���׺�պ���ƫ����
	pos_a = strchr(CHARORDER, toupper(*pa)) - CHARORDER;
	pos_b = strchr(CHARORDER, toupper(*pb)) - CHARORDER;
	if (pos_a > pos_b) // a�ĵ�һ���ַ�������ĸ˳��ʹ���b�ĵ�һ���ַ������a > b
		return 1;
	else if (pos_a < pos_b) // a�ĵ�һ���ַ�������ĸ˳��С��b�ĵ�һ���ַ������a < b
		return -1;
	else
		return cmp_charorder(++pa, ++pb); // // a�ĵ�һ���ַ�������ĸ˳�������b�ĵ�һ���ַ�����Ҫ�����Ƚ�a��b����һ���ַ����ݹ���ã�
}
 
int main() {
	char s[2000]; // ���100�����ʣ�ÿ���������20
	int i, n;
	char words[100][21], *p;
	// �ȶ�ȡ26����д��ĸ����ĸ˳��
	while (gets(CHARORDER) && strlen(CHARORDER) == 26) {
		gets(s); //��ȡ��������ַ���
		n = 0;
		p = strtok(s, " "); //ȡs���Կո�ָ��ĵ�һ������
		
		while (p != NULL) { // ���������Ч
			strcpy(words[n], p); // �����ʸ��Ƶ�words��
			n++;
			p = strtok(NULL, " "); // ������ȡ��һ������
		}
		
		// ��words���������ĸ˳����е�������
		qsort(words, n, 21, cmp_charorder);
		
		for (i = 0; i < n - 1; i++)
			printf("%s ", words[i]);
		printf("%s\n", words[n-1]);
	}
	
	return 0;
}