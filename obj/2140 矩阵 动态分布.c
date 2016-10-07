#include <stdio.h>
#include <stdlib.h>

#define N 1000

int main() {
	int i, j, k, groups;
	int *a, *b, *c;
	int row, col;

	scanf("%d", &groups);

	for (i = 0; i < groups; i++) {
		scanf("%d%d", &row, &col);
		
		a = (int *)malloc(sizeof(int) * row * col);
		b = (int *)malloc(sizeof(int) * row * col);
		c = (int *)malloc(sizeof(int) * row * col);

		for (j = 0; j < row; j++)
			for (k = 0; k < col; k++)
				scanf("%d", &a[j * col + k]);

		for (j = 0; j < row; j++)
			for (k = 0; k < col; k++)
				scanf("%d", &b[j * col + k]);

		for (j = 0; j < row; j++)
			for (k = 0; k < col; k++)
				c[j * col + k] = a[j * col + k] + b[j * col + k];

		for (j = 0; j < row; j++) {
			for (k = 0; k < col-1; k++)
				printf("%d ", c[j * col + k]);
				printf("%d", c[j * col + k]);

			printf("\n");
		}

		free(a);
		free(b);
		free(c);
	}

	return 0;
}

