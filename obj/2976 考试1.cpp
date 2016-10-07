#include <stdio.h>

int main2976() {
	int a[5][5];
	int i, j, k, g, groups;
	int op;

	scanf("%d", &groups);

	for (g = 0; g < groups; g++) {
		for (i = 0; i < 5; i++)
			for (j = 0; j < 5; j++)
				a[i][j] = 1;

		for (i = 1; i <= 3; i++)
			for (j = 1; j <= 3; j++) {
				scanf("%d", &op);
				// 偶数次反转操作等于没有任何反转，奇数次反转操作等于1次。
				if (op % 2 == 1) {
					// ！整数是一种快速取0/1值的方法，!1=0, !0=1, !8=0, !!8=1
					a[i][j] = !a[i][j];
					a[i+1][j] = !a[i+1][j];
					a[i][j+1] = !a[i][j+1];
					a[i-1][j] = !a[i-1][j];
					a[i][j-1] = !a[i][j-1];
				}
			}

		for (i = 1; i <= 3; i++) 
			printf("%d %d %d\n", a[i][1], a[i][2], a[i][3]);

	}

	return 0;
}