#include <stdio.h>

#define MAXLINE 100	// ���100��

void print_radix(int n, int radix); // ������ӡ����n��radix���Ʊ�ʾ

int main() {
	int i;
	int lines;
	int n[MAXLINE], radix[MAXLINE];	

	scanf("%d", &lines);
	for (i = 0; i < lines; i++) {
		if (scanf("%d %d", &n[i], &radix[i]) != 2) {
			printf("�������\n");
			return 1;
		}
	}

	for (i = 0; i < lines; i++) {
		print_radix(n[i], radix[i]); 
		printf("\n");
	}
}

// �õݹ��ӡn��radix����
void print_radix(int n, int radix) {
	static char trans[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (n < 0) {
		putchar('-');
		n = -n;
	}

	if (n >= radix)
		print_radix(n / radix, radix);

	putchar(trans[n % radix]);
}