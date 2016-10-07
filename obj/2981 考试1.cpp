#include <stdio.h>
#include <string.h>

// GCD��a��b�����Լ��
unsigned long long GCD(unsigned long long a, unsigned long long b);

void floatPrecisionExpress(char *numberStr){
	char *p;
	//start��numberStr�ַ����� [ ���ŵ�λ�ã����û�ҵ�����0(NULL)
	char *start = 0;
	//end��numberStr�ַ����� ] ���ŵ�λ�ã����û�ҵ�����0(NULL)
	char *end = 0;
	//point��numberStr�ַ�����С�����λ�ã����û�ҵ�����0(NULL)
	char *point = 0;

	//����Ƿ��ҵ� [ ���� 
	bool isFind = false;
	//��¼�ַ����ĳ��� 
	int len = 0;
	//����molecular����ĸdenominator��m��d�ֱ����ڼ������ѭ��С��[]ʱ�Ķ���ķ��ӷ�ĸ�����������molecular����ĸdenominator�ϲ�
	unsigned long long molecular = 0, denominator = 1, m = 0, d = 1;
	int i = 0;
	
	unsigned long long gcd = 1; // gcd���Լ��������=1����ʾ���ӷ�ĸ����
	// strchr���ַ�����Ѱ��ĳ���ַ���λ�ã����Բ�һ�°���
	start = strchr(numberStr, '[');
	end = strchr(numberStr, ']');
	point = strchr(numberStr, '.');
	
	//ֻ���ҵ� [ �� ] ���ǶԵģ�Ҫô�����ҵ����ҵ�һ����������Ǵ���ģ�ֱ�ӷ���
	if(start && end){
		isFind = true; 
	}
	
	// �Ҳ���С����λ�ã���������
	if (!point) {
		printf("��������ݲ�����С���㣡\n");
		return;
	}

	// ����С����ǰ�ĳ����������11.0[8]����molecular=11, denominator��Ȼ=1���䡣
	for (p = numberStr; p < point; p++)
		molecular = molecular * 10 + (*p - '0'); 

	// ����С�����ģ�������[]ѭ��С��ǰ�ĳ����ͱ���������С��ת��Ϊ����
	// �����11.0[8]����molecular=110, denominator=10��
	for (p = point + 1; *p && p != start; p++) {
		molecular = molecular * 10 +  *p - '0';
		denominator *= 10;
	}

	// ��ѭ��С��
	if (isFind) {
		// �� [ ��ֱ�� ] ǰ��λ�á������11.0[8]����m=8, denominator=10��
		for (p = start + 1; p < end; p++) {
			m = m * 10 + (*p - '0');
			d = d * 10;
		}

		// ��ǰ���ѭ��С�����ֺϲ���
		molecular = molecular * (d - 1) + m;
		denominator = denominator * (d - 1);
	}

	// �������Լ�������һ�д�ӡ���Կ��ø������
	gcd= GCD(molecular, denominator);
	printf("%lld/%lld\n", molecular / gcd, denominator / gcd);
	//printf("(����:%lld,��ĸ:%lld,���Լ��:%lld) - %lld/%lld\n", molecular, denominator, gcd, molecular / gcd, denominator / gcd);
}

// ���Լ�����㷨���кܶ෽�����ã�����ȽϿ졣
unsigned long long GCD(unsigned long long a, unsigned long long b){
	int t;
	if (a < b){
		t = a; a = b; b = t;
	}
	
	while (b > 0) {		
		t = b;
		b = a % b;
		a = t;
	}

	return a;
}

int main(){
	int i, n;
	char v[16+1];
	scanf("%d ", &n);

	for (i = 0; i < n; i++) {
		gets(v);

		printf("case #%d:\n", i);
		floatPrecisionExpress(v);
	}

	//��������
	//floatPrecisionExpress("0.285714[285714]");

	return 0;
}