#include <stdio.h>

int main() {
	int groups;
	int i, x, y;
	int bit_xor, diff; // bit_xor��ʾx��y����������պ���x��y��ͬλ�ı�ʾ��diff������ʾbit_or���м���������1

	scanf("%d", &groups);
	for (i = 0; i < groups; i++) {
		scanf("%d%d", &x, &y);
		bit_xor = x ^ y; // x = 5 = 0101, y = 10 = 1010, x ^ y = 1111
		diff = 0;
		// �������bit_xor���ƣ����ж��ٸ�1��
		while (bit_xor != 0) {
			diff = diff + (bit_xor & 1); // bit_xor & 1 ȡbit_xor���ұߵĶ�����ֵ��0��1����diff�ۼӵĽ���պ���1�ĸ���
			bit_xor >>= 1; // ����һλ
		}

		printf("%d\n", diff);
	}

	return 0;
}