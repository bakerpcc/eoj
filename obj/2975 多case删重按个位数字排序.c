#include <stdio.h>
#include <stdlib.h>

#define T 10
#define N 1000

// ������С��������ȽϺ���
int comp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

// ��λ���ȽϺ���
int comp2(const void *a, const void *b) {
	int m = *(int *)a, n = *(int *)b;
	if (m % 10 > n % 10) // ��λ���Ƚϣ�ȡ�����Ƚϼ���
		return 1;
	else if (m % 10 < n % 10)
		return -1;
	else // ��λ����ȣ������Ƚ�����������Ĵ�С
		if (m < n)
			return -1;
		else
			return 1;
}

int main() {
	int i, j, k, t, s; //ѭ������
	// nums[N]����ĳһ�����������sorted_nums[T][N]��������õ����������
	// group_nums[T]���������ظ������������Ԫ�ظ���
	int nums[N] = {0}, sorted_nums[T][N] = {0}, group_nums[T];
	int groups, num_in_group; // groups������ĵ�һ�����������num_in_group����ÿ�������ֵ�����

	scanf("%d", &groups);

	for (i = 0; i < groups; i++) {
		scanf("%d", &num_in_group); //��ȡ��ǰ�����������
		for (j = 0; j < num_in_group; j++)
			scanf("%d", &nums[j]);

		qsort(nums, j, sizeof(int), comp); //���Ȱ���С��������
		
		//������ǰ����ظ��������浽sorted_nums[i]�С�i�ǵ�ǰ��
		sorted_nums[i][0] = nums[0]; 
		t = 1;
		for (k = 1; k < j; k++)
			if (nums[k] != nums[k - 1]) 
				sorted_nums[i][t++] = nums[k];
		group_nums[i] = t; 
		// �����ظ�����sorted_nums[i]����������С����������û���ظ���
		// ����qsort����λ������
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
