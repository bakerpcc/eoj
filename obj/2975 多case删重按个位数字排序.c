#include <stdio.h>
#include <stdlib.h>

#define T 10
#define N 1000

// 整数从小到大排序比较函数
int comp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

// 个位数比较函数
int comp2(const void *a, const void *b) {
	int m = *(int *)a, n = *(int *)b;
	if (m % 10 > n % 10) // 个位数比较，取余数比较即可
		return 1;
	else if (m % 10 < n % 10)
		return -1;
	else // 个位数相等，继续比较两个数本身的大小
		if (m < n)
			return -1;
		else
			return 1;
}

int main() {
	int i, j, k, t, s; //循环变量
	// nums[N]保存某一组的所有数，sorted_nums[T][N]保存排序好的所有组的数
	// group_nums[T]保存消除重复数后，所有组的元素个数
	int nums[N] = {0}, sorted_nums[T][N] = {0}, group_nums[T];
	int groups, num_in_group; // groups是输入的第一个组的数量，num_in_group保存每组中数字的数量

	scanf("%d", &groups);

	for (i = 0; i < groups; i++) {
		scanf("%d", &num_in_group); //读取当前组的数的数量
		for (j = 0; j < num_in_group; j++)
			scanf("%d", &nums[j]);

		qsort(nums, j, sizeof(int), comp); //首先按从小到大排序
		
		//消除当前组的重复数，保存到sorted_nums[i]中。i是当前组
		sorted_nums[i][0] = nums[0]; 
		t = 1;
		for (k = 1; k < j; k++)
			if (nums[k] != nums[k - 1]) 
				sorted_nums[i][t++] = nums[k];
		group_nums[i] = t; 
		// 消除重复数后，sorted_nums[i]组中数按从小到大排序，且没有重复。
		// 调用qsort按个位数排序
		qsort(sorted_nums[i], t, sizeof(int), comp2);		
	}

	for (i = 0; i < groups; i++) {{
		printf("case #%d:\n", i);
		for (j = 0; j < group_nums[i]-1; j++) {
			printf("%d ", sorted_nums[i][j]);
			}
		printf("%d", sorted_nums[i][j]);	}
		printf("\n");
	}

	return 0;
}
