#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
 
// 字母顺序这里用了全局变量，便于cmp函数使用。默认字母顺序
char CHARORDER[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 
// qsort排序比较函数。其实只要把qsort的比较函数设计好，就能解决大多数问题。本题即为一例。
int cmp_charorder(const void *a, const void *b) {
	char *pa = (char *)a;
	char *pb = (char *)b;
 
	// pos_a, pos_b分别记录a和b当前字符在CHARORDER字母顺序中的相对位置。
	int pos_a, pos_b;
	
	if (*pa == NULL && *pb == NULL) // 两个指针均为空，a==b
		return 0;
	if (*pa == NULL) // a==NULL,b!=NULL, b比a长，a<b 
		return -1;
	else if (*pb == NULL) // b==NULL,a!=NULL, a比b长，a>b 
		return 1;
	
	// 将pa第一个字符转换为大写，然后在CHARORDER中查找该大写字母所在的位置。
	// strchr在指定字符串中查找某个字符的位置，返回值是指向该字符的指针，减去串首后刚好是偏移量
	pos_a = strchr(CHARORDER, toupper(*pa)) - CHARORDER;
	pos_b = strchr(CHARORDER, toupper(*pb)) - CHARORDER;
	if (pos_a > pos_b) // a的第一个字符按照字母顺序就大于b的第一个字符，因此a > b
		return 1;
	else if (pos_a < pos_b) // a的第一个字符按照字母顺序小于b的第一个字符，因此a < b
		return -1;
	else
		return cmp_charorder(++pa, ++pb); // // a的第一个字符按照字母顺序等于于b的第一个字符，需要继续比较a和b的下一个字符。递归调用！
}
 
int main() {
	char s[2000]; // 最多100个单词，每个单词最大20
	int i, n;
	char words[100][21], *p;
	// 先读取26个大写字母的字母顺序
	while (gets(CHARORDER) && strlen(CHARORDER) == 26) {
		gets(s); //读取待排序的字符串
		n = 0;
		p = strtok(s, " "); //取s中以空格分隔的第一个单词
		
		while (p != NULL) { // 如果单词有效
			strcpy(words[n], p); // 将单词复制到words中
			n++;
			p = strtok(NULL, " "); // 继续获取下一个单词
		}
		
		// 将words用输入的字母顺序进行单词排序
		qsort(words, n, 21, cmp_charorder);
		
		for (i = 0; i < n - 1; i++)
			printf("%s ", words[i]);
		printf("%s\n", words[n-1]);
	}
	
	return 0;
}