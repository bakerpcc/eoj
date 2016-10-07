#include <stdio.h>

int main() {
	int group, num;
	int i, j, k, t, count, isfeb;
	long a[21];
	
	scanf("%d", &group);
	for (i = 0; i < group; i++) {
		scanf("%d", &num);
		for(j=0;j<num;j++) {
			scanf("%ld",&a[j]);
			if (a[j] == -1) // 记录-1的位置
				t = j;
		}

		// -1 分别出现在数组0，1，2位置时，需要特殊处理，比如：4 -1 2 3 6 输入的情况
		switch (t) {
		case 0:
			a[t] = a[3] - a[1] - a[2];
			break;
		case 1:
			a[t] = a[3] - a[0] - a[2];
			break;
		case 2:
			a[t] = a[3] - a[0] - a[1];
			break;
		default:
			a[t] = a[t-1] + a[t-2] + a[t-3];
			break;
		}

		printf("case #%d:\n", i);
		isfeb = 1; //假定序列符合三元斐波纳奇数列定义
		// 只管循环判断所有的情况，看看是否符合定义
		for (k = 3; k < num; k++) {
			// 出现与三元斐波纳奇数列定义不符的情况，设置isfeb为假
			if (a[k] != a[k-1]+a[k-2]+a[k-3]) {
				printf("-1\n");
				isfeb = 0; 
				break;
			}
		}

		if (isfeb) // 循环结束仍然为真，则打印
			printf("%d\n", a[t]);
	}

	return 0;
}