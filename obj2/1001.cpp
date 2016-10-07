#include <stdio.h>
#include <string.h>

#define LEN 502

// reverse����һ���ַ����飬�� "abc"���"cba"
void reverse(char *s, int len) {
	int i, j;
	char c;

	for (i = 0, j = len - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

int main1001() {
	char buf[1024], a[LEN], b[LEN], c[LEN], *pc;
	int len_a, len_b, len_c, max_len;
	int i, j, k, m, d, sum;

	while (gets(buf) != NULL) {
		for (i = 0; i < LEN; i++) {
			a[i] = b[i] = c[i] = 0; // ='\0'Ҳһ����ÿ�ζ����
		}

		sscanf(buf, "%s %s", a, b);

		for (i = 0; a[i] != '\0'; i++)
			a[i] = a[i] - '0'; //���ַ���ʾ������ֱ�ӱ������
		len_a = i;

		for (i = 0; b[i] != '\0'; i++)
			b[i] = b[i] - '0';
		len_b = i;
		
		//ȡa��b�ĳ��Ƚϴ��
		if (len_a >= len_b)
			max_len = len_a;
		else
			max_len = len_b;

		// ��a��b���ù����������Ϳ��Դ�ͷ�ӵ�β
		reverse(a, len_a); 
		reverse(b, len_b);

		pc = c;
		
		m = 0; //m��ʾ��һ�μӷ��Ľ�λ����ʼֵΪ0
		// ѭ�������棬a��b�н϶̵��Ǹ���������Ԫ��ֵ�϶�Ϊ0�ˣ�ǰ����0�Ľ��������˾Ͳ������⴦���ĸ����ĸ���
		for (i = 0; i < max_len; i++) {
			sum = a[i] + b[i] + m; // һ��Ҫ�ӽ�λ������������ 999999999999 1�����
			*pc++ = sum % 10 + '0';
			m = sum / 10;
		}

		//�����Ժ����λ���ܻ��н�λ
		if (m > 0)
			*pc++ = m + '0'; 

		reverse(c, pc - c);
		printf("%s\n", c);
	}


	return 0;
}