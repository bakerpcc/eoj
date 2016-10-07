#include <stdio.h>
#include <string.h>

#define LEN 502

// reverse逆向一个字符数组，即 "abc"变成"cba"
void reverse(char *s, int len) {
	int i, j;
	char c;

	for (i = 0, j = len - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

int main1001() {
	char buf[1024], a[LEN], b[LEN], c[LEN], *pc;
	int len_a, len_b, len_c, max_len;
	int i, j, k, m, d, sum;

	while (gets(buf) != NULL) {
		for (i = 0; i < LEN; i++) {
			a[i] = b[i] = c[i] = 0; // ='\0'也一样，每次都清除
		}

		sscanf(buf, "%s %s", a, b);

		for (i = 0; a[i] != '\0'; i++)
			a[i] = a[i] - '0'; //把字符表示的数字直接变成整数
		len_a = i;

		for (i = 0; b[i] != '\0'; i++)
			b[i] = b[i] - '0';
		len_b = i;
		
		//取a和b的长度较大的
		if (len_a >= len_b)
			max_len = len_a;
		else
			max_len = len_b;

		// 把a和b倒置过来，这样就可以从头加到尾
		reverse(a, len_a); 
		reverse(b, len_b);

		pc = c;
		
		m = 0; //m表示上一次加法的进位，初始值为0
		// 循环到后面，a和b中较短的那个，其数组元素值肯定为0了（前面清0的结果），因此就不用特殊处理哪个长哪个短
		for (i = 0; i < max_len; i++) {
			sum = a[i] + b[i] + m; // 一定要加进位，比如输入是 999999999999 1的情况
			*pc++ = sum % 10 + '0';
			m = sum / 10;
		}

		//加完以后最高位可能还有进位
		if (m > 0)
			*pc++ = m + '0'; 

		reverse(c, pc - c);
		printf("%s\n", c);
	}


	return 0;
}