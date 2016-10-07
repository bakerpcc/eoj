#include <stdio.h>
#define M 100

int main() {
	int i, j, k, div, mod; // div存放n和m整除的结果，mod存放n%m
	int n, m, groups;
	int mods[M]; // 1≤n<m≤100，最多100个取模结果。保存每次计算的余数，用于判断余数是否出现了重复，如果重复就表示无限循环

	scanf("%d", &groups);

	for (i = 0; i < groups; i++) {
		scanf("%d%d", &n, &m);

		printf("case #%d:\n%d.",i, n / m); // 这里并没有像题目那样n <= m的限制。可以计算8/7
		mod = n % m; 
		// 处理比如8/8的特殊情况，小数点后面打印一个0
		if (mod == 0) {
			printf("0\n");
			continue;
		}

		j = 0;
		mods[j++] = mod; // 保存第一个余数

		//余数为0，此时小数打印完毕。
		while (mod != 0) { 
			n = mod * 10; // 余数x10后继续除以分母
			printf("%d", n / m);
			mod = n % m;
			
			// 从前面保存的余数数组里面找是否有和当前余数相同的数，如果有，表示出现了循环小数
			for (k = 0; k < j; k++) 
				if (mods[k] == mod) {
					printf("\n%d-%d", k+1, j);
					mod = 0; // 设置mod为0，退出while循环
					break;
				}

			mods[j++] = mod; // 保存当前余数
		}

		printf("\n");
	}

	return 0;
}