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
		m = money / 3; // �����������
		for (i = 0; i <= m; i++) { 
			w = (money - i * 3) / 2; // ����������iȷ��������£�����Ů���������
			for (j = w; j >= 0; j--) {
				c = (money - i * 3 - j * 2); // ����Ů����i��jȷ����ʣ�¾���С���������c
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