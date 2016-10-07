#include <stdio.h>

#define MAXLINE 100	// 最多100行

void print_radix(int n, int radix); // 函数打印整数n的radix进制表示

int main() {
	int i;
	int lines;
	int n[MAXLINE], radix[MAXLINE];	

	scanf("%d", &lines);
	for (i = 0; i < lines; i++) {
		if (scanf("%d %d", &n[i], &radix[i]) != 2) {
			printf("输入错误\n");
			return 1;
		}
	}

	for (i = 0; i < lines; i++) {
		print_radix(n[i], radix[i]); 
		printf("\n");
	}
}

// 用递归打印n的radix进制
void print_radix(int n, int radix) {
	static char trans[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (n < 0) {
		putchar('-');
		n = -n;
	}

	if (n >= radix)
		print_radix(n / radix, radix);

	putchar(trans[n % radix]);
}