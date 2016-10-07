//2821:
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXEXP 50
#define MAXLEN 100

// 思路是：
// 1.读两个串，分别表示两个多项式；
// 2.将一个多项式串用数组表示，用parse函数实现。
// 3.parse函数太复杂，继续分解：将一个多项式分解成一个个独立的项，
//   即将x^2-3x+1分解成：x^2, -3x, +1三个项。用readOne函数实现。
// 4.readOne函数读取多项式的一项，也比较复杂，继续分解，
//   将读取基数和读取阶数的功能分离出来，成为readInt函数。
// 5.最后是一个辅助打印函数printExpression，用不用无所谓，
//   打印一个用数组表示的多项式。
// 6.总结：解题过程是用从高至低，逐步分解细化，分而治之的方法。


// parse函数将s字符串参数分解为多项式并存于a数组参数中，并返回最大阶数
int parse(char *s, int *a);

// readOne函数读取字符串s表示的多项式中的一项，如"x^2-3x+1"中的"x^2"，
// 并将结果保存在数组a中，如100x^200表示为a[200]=100。
// 函数返回串s最后读取到的位置，供后面继续处理；//important!!!
// 如"x^2-3x+1"在读取"x^2"一项后，p指向'-'的位置。
char * readOne(char *s, int *a);

// readInt从p当前位置处读取一个整数，并存入n。注意有可能有正负符号
char * readInt(char *p, int *n);

// 辅助打印函数：打印一个用数组a表示的多项式。
// 参数exponent是a的最高阶，title是打印的标题。
void printExpression(int *a, int exponent, const char *title);

int main() {
	int i, j;
	// a1,a2是读入的两个多项式，a3是结果; 
	// 用数组表示多项式：x^2-3x+1在a里表示为a[2]=1, a[1]=-3, a[0]=1
	int a1[MAXEXP] = {0};
	int a2[MAXEXP] = {0};
	int a3[MAXEXP] = {0}; 

	// 存放abc三个多项式的最大阶数
	int a1exp = 0, a2exp = 0, a3exp = 0; 
	char s1[MAXLEN], s2[MAXLEN]; // s1 s2是空格分隔的两个多项式

	// 读取用空格分隔的两个多项式表达式
	scanf("%s %s", s1, s2);

	// 将s1,s2分别分解为a, b两个数组表示的多项式
	// parse将用字符串表示的多项式转换为用数组表示的多项式，并返回最高阶
	a1exp = parse(s1, a1); 
	printExpression(a1, a1exp, "第一个多项式表达式为");

	a2exp = parse(s2, a2);
	printExpression(a2, a2exp, "第一个多项式表达式为");

	a3exp = a1exp + a2exp; // 多项式相乘，结果的最高阶应该是两个最大阶数之和

	// 计算多项式乘积：从第一个多项式最高阶开始，与第二个相乘
	for (i = a1exp; i >= 0; i--) {
		for (j = a2exp; j >= 0; j--) {
			// 注意这里一定要把a3[i + j]的当前值加上，因为前面的循环当中可能有相同阶的结果，需要合并在一起
			a3[i + j] = a3[i + j] + a1[i] * a2[j];
		}
	}

	printExpression(a3, a3exp, "多项式乘积结果为");

	// 输出c
	printf("----------\n结果为：\n");
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
		// 读取多项式的一个单位，即读取AnX^n
		p = readOne(p, a);
	}

	// 寻找刚读取多项式项的最高阶
	for (i = MAXEXP - 1; i >= 0; i--)
		if (a[i] != 0)
			return i;

	// 没找到，应该不会出现。
	return 0;
}

char * readOne(char *s, int *a) {
	int exponent = 0, base = 0;

	// 如果开始是x，基数就是1
	if (*s == 'x' || *s == 'X')
		base = 1;
	else // 读取基数
		s = readInt(s, &base); 

	if (*s == 'x' || *s == 'X') {
		// 当前位置是x，则阶数至少为1，先置为1。
		exponent = 1;

		s++;
		if (*s == '^') { // '^'表示后面跟着阶数
			s++;
			s = readInt(s, &exponent); //读后面的阶数
		}
	}

	a[exponent] = base; // 保存读取结果

	// printf("exponent=%d, base=%d\n", exponent, base);

	// 必须返回当前读到的位置
	return s;
}

// 从p当前位置读取一个整数，通过n返回；函数返回读取整数后的位置。
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

	// atoi函数将一个用字符串表示的数转换成整数。atof函数是转换成浮点数。
	*n = atoi(tmp);
	//printf("tmp = %s, v=%d\n", tmp, *n);
	return p;
}

// 打印一个由数组表示的多项式
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
