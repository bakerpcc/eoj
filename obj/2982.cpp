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
			if (a[j] == -1) // ��¼-1��λ��
				t = j;
		}

		// -1 �ֱ����������0��1��2λ��ʱ����Ҫ���⴦�����磺4 -1 2 3 6 ��������
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
		isfeb = 1; //�ٶ����з�����Ԫ쳲��������ж���
		// ֻ��ѭ���ж����е�����������Ƿ���϶���
		for (k = 3; k < num; k++) {
			// ��������Ԫ쳲��������ж��岻�������������isfebΪ��
			if (a[k] != a[k-1]+a[k-2]+a[k-3]) {
				printf("-1\n");
				isfeb = 0; 
				break;
			}
		}

		if (isfeb) // ѭ��������ȻΪ�棬���ӡ
			printf("%d\n", a[t]);
	}

	return 0;
}