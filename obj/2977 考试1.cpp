#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 500
#define M 10

// 每行学生输入记录，如：10091130015 3 5 1 3
typedef struct {
	char no[12]; // no=10091130015
	long len; // len=3
	long pass[M]; //pass[0..2]=5 1 3
	long total; // total在输入时计算累计总分。
} exam;

int cmpscore(const void *a, const void *b)
{
	exam *s1, *s2;

	s1 = (exam *)a;
	s2 = (exam *)b;
	// 总分相同，按学号从小到大排序
	if (s1->total == s2->total)
		return strcmp(s1->no, s2->no);
	
	// 总分不同，按从大到小
	return s2->total - s1->total;
}

int main() {
	exam s[N]; //每组的学生成绩记录
	int points[M]; //从第1题至第M题每道题的分值，保存在points[0..M-1]中
	int groups, students, m, g;
	int i,j,k,passed_num; //passed_num记录每组中不低于分数线的人数

	scanf("%d", &groups);
	for (i = 0; i < groups; i++) {
		// 每组的第一行输入，学生数，题目数，分数线
		scanf("%d%d%d", &students, &m, &g);
		for (j = 0; j < m; j++)
			scanf("%d", &points[j]); // 读取每题的分值

		passed_num = 0;
		for (j = 0; j < students; j++) {
			// 读取学号和该学生解出的题目总数，只有读取了解题总数后才能读取接了哪些题。
			scanf("%s%d", &s[j].no, &s[j].len);
			// total存放该学生解题的总分
			s[j].total = 0;
			
			for (k = 0; k < s[j].len; k++) {
				scanf("%d", &s[j].pass[k]);
				// s[j].pass[k] - 1 对应points解题分值的下标
				s[j].total += points[s[j].pass[k] - 1];
			}

			if (s[j].total >= g) // 总分不低于分数线
				passed_num++;
		}
		
		// 按总分递减，学号递增排序。
		qsort(s, students, sizeof(exam), cmpscore);

		printf("case #%d\n%d\n", i, passed_num);
		for (j = 0; j < passed_num; j++)
			printf("%s %d\n", s[j].no, s[j].total);
	}

	return 0;
}