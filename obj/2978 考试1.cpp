#include <stdio.h>

int main() {
	int t;
	int i, j, sum, ge, shi, bai;
	unsigned long long a, m, n;

	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%lld", &a);
		m = a;
		n = 0; // n��a��λ��
		sum = 0; // sum�Ǹ�λ��֮��
		// ��a��λ��n, ��a�ĸ�λ��֮��
		while (m > 0) {
			n++;
			sum = sum + m % 10;
			m /= 10;
		}
		
		ge = a % 10;
		shi = a / 10 % 10;
		bai = a / 100 % 10;
		// m��a�����㷽����Ľ��
		m = a * 10 + (shi + bai) * ge % 10;

		// ѭ�� (a - n)��
		for (j = n + 1; j <= a; j++) {
			ge = m % 10;
			shi = m / 10 % 10;
			bai = m / 100 % 10;

			if (ge == 0)
				break;

			sum += ge; // ÿѭ��һ�Σ��ͼ��ϸ�λ��
			m = m * 10 + (shi + bai) * ge % 10;
		}

		printf("case #%d:\n%d\n", i, sum);
	}

	return 0;
}