//2821:
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXEXP 50
#define MAXLEN 100

// ˼·�ǣ�
// 1.�����������ֱ��ʾ��������ʽ��
// 2.��һ������ʽ���������ʾ����parse����ʵ�֡�
// 3.parse����̫���ӣ������ֽ⣺��һ������ʽ�ֽ��һ�����������
//   ����x^2-3x+1�ֽ�ɣ�x^2, -3x, +1�������readOne����ʵ�֡�
// 4.readOne������ȡ����ʽ��һ�Ҳ�Ƚϸ��ӣ������ֽ⣬
//   ����ȡ�����Ͷ�ȡ�����Ĺ��ܷ����������ΪreadInt������
// 5.�����һ��������ӡ����printExpression���ò�������ν��
//   ��ӡһ���������ʾ�Ķ���ʽ��
// 6.�ܽ᣺����������ôӸ����ͣ��𲽷ֽ�ϸ�����ֶ���֮�ķ�����


// parse������s�ַ��������ֽ�Ϊ����ʽ������a��������У�������������
int parse(char *s, int *a);

// readOne������ȡ�ַ���s��ʾ�Ķ���ʽ�е�һ���"x^2-3x+1"�е�"x^2"��
// �����������������a�У���100x^200��ʾΪa[200]=100��
// �������ش�s����ȡ����λ�ã��������������//important!!!
// ��"x^2-3x+1"�ڶ�ȡ"x^2"һ���pָ��'-'��λ�á�
char * readOne(char *s, int *a);

// readInt��p��ǰλ�ô���ȡһ��������������n��ע���п�������������
char * readInt(char *p, int *n);

// ������ӡ��������ӡһ��������a��ʾ�Ķ���ʽ��
// ����exponent��a����߽ף�title�Ǵ�ӡ�ı��⡣
void printExpression(int *a, int exponent, const char *title);

int main() {
	int i, j;
	// a1,a2�Ƕ������������ʽ��a3�ǽ��; 
	// �������ʾ����ʽ��x^2-3x+1��a���ʾΪa[2]=1, a[1]=-3, a[0]=1
	int a1[MAXEXP] = {0};
	int a2[MAXEXP] = {0};
	int a3[MAXEXP] = {0}; 

	// ���abc��������ʽ��������
	int a1exp = 0, a2exp = 0, a3exp = 0; 
	char s1[MAXLEN], s2[MAXLEN]; // s1 s2�ǿո�ָ�����������ʽ

	// ��ȡ�ÿո�ָ�����������ʽ���ʽ
	scanf("%s %s", s1, s2);

	// ��s1,s2�ֱ�ֽ�Ϊa, b���������ʾ�Ķ���ʽ
	// parse�����ַ�����ʾ�Ķ���ʽת��Ϊ�������ʾ�Ķ���ʽ����������߽�
	a1exp = parse(s1, a1); 
	printExpression(a1, a1exp, "��һ������ʽ���ʽΪ");

	a2exp = parse(s2, a2);
	printExpression(a2, a2exp, "��һ������ʽ���ʽΪ");

	a3exp = a1exp + a2exp; // ����ʽ��ˣ��������߽�Ӧ��������������֮��

	// �������ʽ�˻����ӵ�һ������ʽ��߽׿�ʼ����ڶ������
	for (i = a1exp; i >= 0; i--) {
		for (j = a2exp; j >= 0; j--) {
			// ע������һ��Ҫ��a3[i + j]�ĵ�ǰֵ���ϣ���Ϊǰ���ѭ�����п�������ͬ�׵Ľ������Ҫ�ϲ���һ��
			a3[i + j] = a3[i + j] + a1[i] * a2[j];
		}
	}

	printExpression(a3, a3exp, "����ʽ�˻����Ϊ");

	// ���c
	printf("----------\n���Ϊ��\n");
	for (i = a3exp; i >= 0; i--) {
		if (a3[i] != 0)
			printf("%d ", a3[i]);
	}	

	printf("\n");

	return 0;
}

int parse(char *s, int *a) {
	int i;
	char *p = s;

	while (*p != 0) {
		// ��ȡ����ʽ��һ����λ������ȡAnX^n
		p = readOne(p, a);
	}

	// Ѱ�Ҹն�ȡ����ʽ�����߽�
	for (i = MAXEXP - 1; i >= 0; i--)
		if (a[i] != 0)
			return i;

	// û�ҵ���Ӧ�ò�����֡�
	return 0;
}

char * readOne(char *s, int *a) {
	int exponent = 0, base = 0;

	// �����ʼ��x����������1
	if (*s == 'x' || *s == 'X')
		base = 1;
	else // ��ȡ����
		s = readInt(s, &base); 
	//��������µ������������ģ�

	//������������硰1�������ĳ������ֻ����else s=readInt(s,&base)���
	//���ĵ�if (*s == 'x' || *s == 'X')��2���������ˣ�����ֱ��exponent = 0
	//a[exponent] = baseΪa[0]=2,��Ϊ0�η��ĳ�������2��

	//���������x��������������if (*s == 'x' || *s == 'X') base = 1;
	//��ʱsָ�뻹ָ��x,���ܼ��������·��� if (*s == 'x' || *s == 'X') 
	//��exponent=1��s++��*s��Ϊ��^����������������ˣ���a[exponent] = base��Ϊa[1]=1,��ζx��

	//���������x^2��������ϵ��Ϊ1����ָ����Ϊ1�����if (*s == 'x' || *s == 'X') base = 1;
	//if (*s == 'x' || *s == 'X') exponent = 1;��ָ������Ϊ1����ʱ�趨Ϊ1�����»�����
	//s++��*s=^,��s++��s = readInt(s, &exponent)��������Ľ�����2����
	//a[2]=1

	//���������3x^2������ϵ����������Ϊ1�ģ����Ϸ�else s = readInt(s, &base)��ȡϵ��3��
	//Ȼ�����£�readInt�Ƿ��ض�ȡ�������λ�ã������Ѿ�������3�����x
	//exp����Ϊ1�󣬼������£���ȡָ��2��Ȼ��a[exponent] = baseΪa[2]=3

	//����Ҫע�����readInt���base��exponent��Ӧ���Ǻ����������*n
	//*n = atoi(tmp)��*n��ŵ���һ������������ָ����ϵ�������Ժ�������ʱҪ��&��

	//����Ϊ��Ҫ��char * readInt(char *p, int *n)������int n�����պ�ƤP227-228��swap
	

	if (*s == 'x' || *s == 'X') {
		// ��ǰλ����x�����������Ϊ1������Ϊ1��
		exponent = 1;

		s++;
		if (*s == '^') { // '^'��ʾ������Ž���
			s++;
			s = readInt(s, &exponent); //������Ľ���
		}
	}

	a[exponent] = base; // �����ȡ���

	// printf("exponent=%d, base=%d\n", exponent, base);

	// ���뷵�ص�ǰ������λ��
	return s;
}

// ��p��ǰλ�ö�ȡһ��������ͨ��n���أ��������ض�ȡ�������λ�á�
char * readInt(char *p, int *n) {
	char tmp[MAXLEN] = {0};
	int i = 0;
	if (*p == '-' || *p == '+') {
		tmp[i] = *p;
		p++;
		i++;
	}

	while (*p >= '0' && *p <= '9') {
		tmp[i] = *p;
		p++;
		i++;
	}

	// atoi������һ�����ַ�����ʾ����ת����������atof������ת���ɸ�������
	*n = atoi(tmp);
	//printf("tmp = %s, v=%d\n", tmp, *n);
	return p;
}

// ��ӡһ���������ʾ�Ķ���ʽ
void printExpression(int *a, int exponent, const char *title) {
	int i;
	printf("%s\t :  ", title);
	for (i = exponent; i >= 0; i--) {
		if (a[i] != 0) {
			if (a[i] > 0 && i < exponent)
				printf("+");
			if (a[i] != 1 || i == 0)
				printf("%d", a[i]);
							
			if (i > 1)
				printf("x^%d", i);
			else if (i == 1)
				printf("x");
		}
	}

	printf("\n");
}
