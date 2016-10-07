#include <stdio.h>
#include <stdlib.h>

#define N 1000
#define MAXNUM_PER_LINE 50

int row_cmp(const void *a, const void *b) {
	long long *pa = (long long *)a;
	long long *pb = (long long *)b;

	// ѭ���Ƚ�ֱ���ҵ����������һ����ͬ��Ԫ��
	while (*pa != -1 && *pb != -1 && *pa == *pb) {
		pa++; pb++;
	}
	
	if (*pa == -1 && *pb == -1) //�������һ��������ǰ��Ƚ϶���ȣ���ô��������������ȵ�
		return 0;
	
	return *pb - *pa; // �Ӵ�С����, *pb - *pa; ��С����ͷ�����
}

int main() {
	//��ĿҪ����0��ai��10^9��������int��long�ķ�Χ��32λ��
	//����Ϊÿ��������-1���������ÿ�ж���Ҫ�����һ���ռ䱣��-1
	long long a[N][MAXNUM_PER_LINE+1]; 
	int i, j, k;
	int groups, lines;

	scanf("%d", &groups);

	for (i = 0; i < groups; i++) {
		scanf("%d", &lines);

		for (j = 0; j < lines; j++) {
			k = 0;
			// ѭ����ȡ��ֱ���������Ϊ-1��ע��-1��ʵҲ�������������汣���ˣ���Ϊ��������Ԫ�����н����ı�־
			while(scanf("%lld", &a[j][k]) == 1 && a[j][k] != -1)
				k++;
		}

		// qsort���ñȽϺ������Դﵽ����������
		// ��������qsort��a��������lines�У�ÿ��sizeof(a) / N���ֽڣ��̶��ģ�Ҳ����д��(MAXNUM_PER_LINE+1) * sizeof(long long)��
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