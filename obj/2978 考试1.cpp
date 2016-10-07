#include <stdio.h>

int main() {
	int t;
	int i, j, sum, ge, shi, bai;
	unsigned long long a, m, n;

	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%lld", &a);
		m = a;
		n = 0; // n是a的位数
		sum = 0; // sum是各位数之和
		// 求a的位数n, 及a的各位数之和
		while (m > 0) {
			n++;
			sum = sum + m % 10;
			m /= 10;
		}
		
		ge = a % 10;
		shi = a / 10 % 10;
		bai = a / 100 % 10;
		// m是a按计算方法后的结果
		m = a * 10 + (shi + bai) * ge % 10;

		// 循环 (a - n)次
		for (j = n + 1; j <= a; j++) {
			ge = m % 10;
			shi = m / 10 % 10;
			bai = m / 100 % 10;

			if (ge == 0)
				break;

			sum += ge; // 每循环一次，就加上个位数
			m = m * 10 + (shi + bai) * ge % 10;
		}

		printf("case #%d:\n%d\n", i, sum);
	}

	return 0;
}