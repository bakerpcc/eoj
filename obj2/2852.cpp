#include <stdio.h>

int main444() {
	int c;
	// max记录出现最多次数的字母，total记录输入字母的总数，freq记录26个字母各自出现的次数
	int i, max, total, freq[26] = { 0 };

	max = 0; total = 0;
	//c=getchar(),c必须声明为整数，这是getchar函数原型的要求
	while ((c = getchar()) != NULL) {
		if (c == '\n') // 碰到回车就结束了
			break;
		if (c == ' ' || c == '\t') //碰到空白字符就跳过
			continue;

		total++; 
		freq[c-'a']++; //freq[0]表示a。。。freq[25]表示z
		if (freq[c-'a'] > max) // max比当前字母出现次数小
			max = freq[c-'a'];
	}

	for (i = 0; i < 26; i++)
		if (max == freq[i]) {
			printf("%c %.2f\n", i+'a', (float)max / total);
			break;
		}

	return 0;
}