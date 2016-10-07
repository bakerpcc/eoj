#include<stdio.h>
#include<stdlib.h>

int main() {
	int group,r,a[10][10];
	// mi，mj分别代表i，j下标的方向，填数顺序是 往右(i不变，j+1)->往下(i+1,j不变)->往左(i不变，j-1)->往上(i-1,j不变)，
	// mi和mj的0，1，2，3分别代表上面的四个方向，循环时只要加上对应方向的mi，mj下标，就能变换。
	int mi[] = {0, 1, 0, -1}; 
	int mj[] = {1, 0, -1, 0};
	int i,j,k,count,m, r1, r2, r3;
	int incr;
	scanf("%d",&group);

	for(m=0;m<group;m++) {
		scanf("%d",&r);		
		incr = 1;
		k = r - 1;
		// 每次循环设置最外面一圈的值，即按4个方向分别赋值。共r/2圈，对于奇数，最后一个元素需单独处理。
		for (r1 = 0; r1 < r / 2; r1++) {
			i = j = r1; // 第r1圈起始位置，即(0,0),(1,1),(2,2)...
			// 循环四次，代表四个方向
			for (r2 = 0; r2 < 4; r2++) {
				//每个方向分别填k个数字，对于8维数组，填7个数字后转向，类推
				for (r3 = 0; r3 < k; r3++) {
					a[i][j] = incr++;
					i = i + mi[r2];
					j = j + mj[r2];
				}
			}
			k -= 2; // 每一圈填完后，缩小两个
		}
		if (r % 2 == 1)
			a[r/2][r/2] = incr;

		printf("case #%d:\n",m);

		for(r1=0; r1<r; r1++)
		{
			for(r2=0; r2 < r;r2++)
				printf("%d ",a[r1][r2]);

			printf("\n");
		}
	}

	return 0;

}