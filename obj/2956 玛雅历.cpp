#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 10000
#define LEN 80
#define MONTHS 19

static char *months[MONTHS] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", 
	"chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};

int compare_maya(const void *a, const void *b) {
	int i;
	int d1, d2, m1, m2, y1, y2;
	char mon1[LEN], mon2[LEN];
	char *s1, *s2;
	s1 = (char *)a;
	s2 = (char *)b;

	sscanf(s1, "%d. %s %d", &d1, mon1, &y1);
	sscanf(s2, "%d. %s %d", &d2, mon2, &y2);

	for (i = 0; i < MONTHS; i++) {
		if (strcmp(months[i], mon1) == 0) 
			m1 = i;
		if (strcmp(months[i], mon2) == 0) 
			m2 = i;
	}

	if (y1 == y2) {
		if (m1 == m2)
			return d1 - d2; // 年月相等，比较日
		else if (m1 < m2) // 年相同，月份小
			return -1;
		else // 年相同，月份大
			return 1;
	}
	else if (y1 < y2) // 年份小
		return -1;
	else // 年份大
		return 1;
}

int main() {
	char line[N][LEN];
	int i, j, groups, num_in_group;

	scanf("%d", &groups);

	for (i = 0; i < groups; i++) {
		scanf("%d ", &num_in_group);
		
		for (j = 0; j < num_in_group; j++) {
			gets(line[j]);
		}

		qsort(line, num_in_group, sizeof(line[0]), compare_maya);

		printf("case #%d:\n", i);
		for (j = 0; j < num_in_group; j++)
			puts(line[j]);
	}

	return 0;
}