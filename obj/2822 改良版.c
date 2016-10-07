#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printBytes(unsigned char *b, int size);

int main(int argc, char const *argv[])
{
	char s[80] = {0};
	int i = 0;
	double f = 0;

	while (gets(s) != NULL) {
		// 输入空白行就退出
		if (strlen(s) == 0)
			break;

		// strchr从s中寻找一个字符，找不到则返回NULL
		// 也可以自己用循环去找。
		if (strchr(s, '.') != NULL) { 
			// 包含小数点，是浮点数
			sscanf(s, "%lf", &f);

			// 用(unsigned char *)&f 把f强制转换为字符指针，计算double长度
			printBytes((unsigned char *)&f, sizeof(double));
		}
		else {
			sscanf(s, "%d", &i);
			// 用(unsigned char *)&i 把f强制转换为字符指针，计算int长度
			printBytes((unsigned char *)&i, sizeof(int));
		}
	}

	return 0;
}

// b可以看成一个8位的字节/字符数组
void printBytes(unsigned char *b, int size) {
	int i;
	for (i = 0; i < size; i++) {
		// %02x表示打印2位16进制的数字，如果为0也要打印而不是不打印
		printf("%02x ", b[i]);
	}
	printf("\n");
}