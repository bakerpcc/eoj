#include <stdio.h>
#define M 100

int main() {
	int i, j, k, div, mod; // div���n��m�����Ľ����mod���n%m
	int n, m, groups;
	int mods[M]; // 1��n<m��100�����100��ȡģ���������ÿ�μ���������������ж������Ƿ�������ظ�������ظ��ͱ�ʾ����ѭ��

	scanf("%d", &groups);

	for (i = 0; i < groups; i++) {
		scanf("%d%d", &n, &m);

		printf("case #%d:\n%d.",i, n / m); // ���ﲢû������Ŀ����n <= m�����ơ����Լ���8/7
		mod = n % m; 
		// �������8/8�����������С��������ӡһ��0
		if (mod == 0) {
			printf("0\n");
			continue;
		}

		j = 0;
		mods[j++] = mod; // �����һ������

		//����Ϊ0����ʱС����ӡ��ϡ�
		while (mod != 0) { 
			n = mod * 10; // ����x10��������Է�ĸ
			printf("%d", n / m);
			mod = n % m;
			
			// ��ǰ�汣������������������Ƿ��к͵�ǰ������ͬ����������У���ʾ������ѭ��С��
			for (k = 0; k < j; k++) 
				if (mods[k] == mod) {
					printf("\n%d-%d", k+1, j);
					mod = 0; // ����modΪ0���˳�whileѭ��
					break;
				}

			mods[j++] = mod; // ���浱ǰ����
		}

		printf("\n");
	}

	return 0;
}