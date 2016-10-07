#include <stdio.h>
 
int main() {
	unsigned int a, b, c, mask;
	int n;
 
	scanf("%d%d", &a, &n);
	//∂¡»Îa£¨n
	mask = ~(~0 << n);
 
	b = (a & mask) << (sizeof (unsigned int) * 8 - n);
	c = a >> n;
	c = c | b;
 
	printf("%u\n", c);
	return 0;
}