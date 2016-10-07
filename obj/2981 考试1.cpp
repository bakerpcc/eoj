#include <stdio.h>
#include <string.h>

// GCD求a和b的最大公约数
unsigned long long GCD(unsigned long long a, unsigned long long b);

void floatPrecisionExpress(char *numberStr){
	char *p;
	//start是numberStr字符串中 [ 符号的位置，如果没找到就是0(NULL)
	char *start = 0;
	//end是numberStr字符串中 ] 符号的位置，如果没找到就是0(NULL)
	char *end = 0;
	//point是numberStr字符串中小数点的位置，如果没找到就是0(NULL)
	char *point = 0;

	//标记是否找到 [ 符号 
	bool isFind = false;
	//记录字符串的长度 
	int len = 0;
	//分子molecular，分母denominator，m和d分别用于计算存在循环小数[]时的额外的分子分母，最后会与分子molecular，分母denominator合并
	unsigned long long molecular = 0, denominator = 1, m = 0, d = 1;
	int i = 0;
	
	unsigned long long gcd = 1; // gcd最大公约数，至少=1，表示分子分母互质
	// strchr在字符串中寻找某个字符的位置，可以查一下帮助
	start = strchr(numberStr, '[');
	end = strchr(numberStr, ']');
	point = strchr(numberStr, '.');
	
	//只有找到 [ 和 ] 才是对的，要么都不找到，找到一个地情况下是错误的，直接返回
	if(start && end){
		isFind = true; 
	}
	
	// 找不到小数点位置，输入有误
	if (!point) {
		printf("输入的数据不包含小数点！\n");
		return;
	}

	// 计算小数点前的除数。如果是11.0[8]，则molecular=11, denominator仍然=1不变。
	for (p = numberStr; p < point; p++)
		molecular = molecular * 10 + (*p - '0'); 

	// 计算小数点后的，并且在[]循环小数前的除数和被除数，将小数转换为整数
	// 如果是11.0[8]，则molecular=110, denominator=10。
	for (p = point + 1; *p && p != start; p++) {
		molecular = molecular * 10 +  *p - '0';
		denominator *= 10;
	}

	// 是循环小数
	if (isFind) {
		// 从 [ 后，直到 ] 前的位置。如果是11.0[8]，则m=8, denominator=10。
		for (p = start + 1; p < end; p++) {
			m = m * 10 + (*p - '0');
			d = d * 10;
		}

		// 与前面非循环小数部分合并。
		molecular = molecular * (d - 1) + m;
		denominator = denominator * (d - 1);
	}

	// 计算最大公约数。最后一行打印可以看得更清楚。
	gcd= GCD(molecular, denominator);
	printf("%lld/%lld\n", molecular / gcd, denominator / gcd);
	//printf("(分子:%lld,分母:%lld,最大公约数:%lld) - %lld/%lld\n", molecular, denominator, gcd, molecular / gcd, denominator / gcd);
}

// 最大公约数的算法，有很多方法可用，这个比较快。
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

	//测试数据
	//floatPrecisionExpress("0.285714[285714]");

	return 0;
}