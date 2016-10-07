#include <stdio.h>

#define N 5000

int main() {
	int i, j, k, m, t;
	int groups, num_in_group;
	int sum, max;
	int a[N+1];

	scanf("%d", &groups);
	for (i = 0; i < groups; i++) {
		scanf("%d", &num_in_group);

		for (j = 0; j < num_in_group; j++)
			scanf("%d", &a[j]);

		max = sum = 0;
		for (j = 0; j < num_in_group; j++) {			
			for (k = j + 1; k < num_in_group; k++) {
				t = j;
				sum = a[j];
				for (m = k; m < num_in_group; m++)
					if (a[t] <= a[m]) {
						t = m;
						sum += a[m];
					}
				if (max < sum)
					max = sum;
			}
		}

		printf("case#%d:\n%d\n", i, max);
	}
}