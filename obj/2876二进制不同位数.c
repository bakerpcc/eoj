#include <stdio.h>

int main() {
	int groups;
	int i, x, y;
	int bit_xor, diff; // bit_xor表示x和y的异或结果，刚好是x和y不同位的表示。diff用来表示bit_or中有几个二进制1

	scanf("%d", &groups);
	for (i = 0; i < groups; i++) {
		scanf("%d%d", &x, &y);
		bit_xor = x ^ y; // x = 5 = 0101, y = 10 = 1010, x ^ y = 1111
		diff = 0;
		// 把异或结果bit_xor右移，看有多少个1。
		while (bit_xor != 0) {
			diff = diff + (bit_xor & 1); // bit_xor & 1 取bit_xor最右边的二进制值（0或1），diff累加的结果刚好是1的个数
			bit_xor >>= 1; // 右移一位
		}

		printf("%d\n", diff);
	}

	return 0;
}