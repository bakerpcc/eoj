#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 500
#define M 10

// ÿ��ѧ�������¼���磺10091130015 3 5 1 3
typedef struct {
	char no[12]; // no=10091130015
	long len; // len=3
	long pass[M]; //pass[0..2]=5 1 3
	long total; // total������ʱ�����ۼ��ܷ֡�
} exam;

int cmpscore(const void *a, const void *b)
{
	exam *s1, *s2;

	s1 = (exam *)a;
	s2 = (exam *)b;
	// �ܷ���ͬ����ѧ�Ŵ�С��������
	if (s1->total == s2->total)
		return strcmp(s1->no, s2->no);
	
	// �ֲܷ�ͬ�����Ӵ�С
	return s2->total - s1->total;
}

int main() {
	exam s[N]; //ÿ���ѧ���ɼ���¼
	int points[M]; //�ӵ�1������M��ÿ����ķ�ֵ��������points[0..M-1]��
	int groups, students, m, g;
	int i,j,k,passed_num; //passed_num��¼ÿ���в����ڷ����ߵ�����

	scanf("%d", &groups);
	for (i = 0; i < groups; i++) {
		// ÿ��ĵ�һ�����룬ѧ��������Ŀ����������
		scanf("%d%d%d", &students, &m, &g);
		for (j = 0; j < m; j++)
			scanf("%d", &points[j]); // ��ȡÿ��ķ�ֵ

		passed_num = 0;
		for (j = 0; j < students; j++) {
			// ��ȡѧ�ź͸�ѧ���������Ŀ������ֻ�ж�ȡ�˽�����������ܶ�ȡ������Щ�⡣
			scanf("%s%d", &s[j].no, &s[j].len);
			// total��Ÿ�ѧ��������ܷ�
			s[j].total = 0;
			
			for (k = 0; k < s[j].len; k++) {
				scanf("%d", &s[j].pass[k]);
				// s[j].pass[k] - 1 ��Ӧpoints�����ֵ���±�
				s[j].total += points[s[j].pass[k] - 1];
			}

			if (s[j].total >= g) // �ֲܷ����ڷ�����
				passed_num++;
		}
		
		// ���ֵܷݼ���ѧ�ŵ�������
		qsort(s, students, sizeof(exam), cmpscore);

		printf("case #%d\n%d\n", i, passed_num);
		for (j = 0; j < passed_num; j++)
			printf("%s %d\n", s[j].no, s[j].total);
	}

	return 0;
}