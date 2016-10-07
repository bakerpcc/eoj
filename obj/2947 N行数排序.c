#include <stdio.h>
#include <stdlib.h>

#define N 1000
#define MAXNUM_PER_LINE 50

int row_cmp(const void *a, const void *b) {
	long long *pa = (long long *)a;
	long long *pb = (long long *)b;

	// 循环比较直到找到两个数组第一个不同的元素
	while (*pa != -1 && *pb != -1 && *pa == *pb) {
		pa++; pb++;
	}
	
	if (*pa == -1 && *pb == -1) //如果两个一样长，且前面比较都相等，那么这两个数组是相等的
		return 0;
	
	return *pb - *pa; // 从大到小排序, *pb - *pa; 从小到大就反过来
}

int main() {
	//题目要求是0≤ai≤10^9，超出了int和long的范围（32位）
	//又因为每行数都以-1结束，因此每行都需要多分配一个空间保存-1
	long long a[N][MAXNUM_PER_LINE+1]; 
	int i, j, k;
	int groups, lines;

	scanf("%d", &groups);

	for (i = 0; i < groups; i++) {
		scanf("%d", &lines);

		for (j = 0; j < lines; j++) {
			k = 0;
			// 循环读取，直到输入的数为-1，注意-1其实也读到了数组里面保存了，作为数组里面元素序列结束的标志
			while(scanf("%lld", &a[j][k]) == 1 && a[j][k] != -1)
				k++;
		}

		// qsort利用比较函数可以达到很灵活的排序，
		// 在这里用qsort对a按行排序，lines行，每行sizeof(a) / N个字节（固定的，也可以写成(MAXNUM_PER_LINE+1) * sizeof(long long)）
		qsort(a, lines, sizeof(a) / N, row_cmp);

		for (j = 0; j < lines; j++) {
			k = 0;
			printf("%d",a[j][k]);
			k++;
			while (a[j][k] != -1) {
				printf(" %d", a[j][k]);
				k++;
			}
			printf("\n");
		}
	}

	return 0;
}