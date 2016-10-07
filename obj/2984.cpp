#include <stdio.h>

int main() {
	int m, w, c;
	int groups, people, money;
	int i, j, k, g;
	int found;

	scanf ("%d", &groups);
	for (g = 0; g < groups; g++) {
		scanf("%d%d", &people, &money);
		found = 0;
		printf("case #%d:\n", g);
		m = money / 3; // 男人最大人数
		for (i = 0; i <= m; i++) { 
			w = (money - i * 3) / 2; // 在男人人数i确定的情况下，计算女人最大人数
			for (j = w; j >= 0; j--) {
				c = (money - i * 3 - j * 2); // 在男女人数i，j确定后，剩下就是小孩最大人数c
				if (i + j + c == people && i * 3 + j * 2 + c == money) {
					printf("%d %d %d\n", i, j, c);
					found = 1;
				}
			}
		}

		if (!found)
			printf("-1\n");
	}

	return 0;
}