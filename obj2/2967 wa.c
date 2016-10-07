#include <stdio.h>
#include <stdlib.h>

#define LEN 100

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int main() {
	int groups;
	int len_a, len_b, len_c, min_len, a[LEN], b[LEN], c[LEN];
	int *p1, *p2, *p3;
	int i, j, k, found;

	scanf("%d", &groups);

	for (i = 0; i < groups; i++) {
		scanf("%d%d%d", &len_a, &len_b, &len_c);

		for (j = 0; j < len_a; j++)
			scanf("%d", &a[j]);
		for (j = 0; j < len_b; j++)
			scanf("%d", &b[j]);
		for (j = 0; j < len_c; j++)
			scanf("%d", &c[j]);
		
		qsort(a, len_a, sizeof(int), cmp);
		qsort(b, len_b, sizeof(int), cmp);
		qsort(c, len_c, sizeof(int), cmp);

		/***************************/
		// 从这里一直到下面****结束，是为了提高运行效率，找出最短的一个数组，
		// 然后用这个数组中的元素逐一在另外两个数组中搜索，比如数组的大小分别是1000 100 1
		// 如果不用这种方法，直接用a（1000个元素）去搜索，效率会低些。
		// 用qsort对数组排序，是为了用bsearch库函数进行快速搜索。bsearch是二分法查找，效率高，但要求数组必须实现排序。
		min_len = len_a; 
		if (min_len > len_b)
			min_len = len_b;
		if (min_len > len_c)
			min_len = len_c;

		if (min_len == len_a) {
			p1 = a; p2 = b; p3 = c;
		}
		else if (min_len == len_b) {
			p1 = b; p2 = a; p3 = c;
		}
		else {
			p1 = c; p2 = a; p3 = b;
		}
		/***************************/

		printf("case #%d:\n", i);
		found = 0;
		for (j = 0; j < min_len-1; j++) {
			if (bsearch(&p1[j], b, len_b, sizeof(int), cmp) && bsearch(&p1[j], c, len_c, sizeof(int), cmp)) {
				printf("%d ", p1[j]);
				found = 1;
			}
		}
		if (bsearch(&p1[j], b, len_b, sizeof(int), cmp) && bsearch(&p1[j], c, len_c, sizeof(int), cmp)) {
				printf("%d", p1[j]);
				found = 1;}
		if (!found)
			printf("-1");
		// 如果不用上面的效率改进，可删除上面整段******之间的内容，并且用下面这段循环来执行
		/*for (j = 0; j < len_a; j++) {
			if (bsearch(&a[j], b, len_b, sizeof(int), cmp) && bsearch(&a[j], c, len_c, sizeof(int), cmp))
				printf("%d ", p1[j]);
		}*/

		printf("\n");
	
	}
	return 0;
}