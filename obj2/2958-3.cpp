#include<stdio.h>
#include<stdlib.h>

// 可以换个思路：假定输入为a1,a2,...an， 可以用M[i]表示以ai结尾的最大子序列;
// 初始化时，可以设定M[i] = 0, 表示最大子序列和都是0。
// 以a1结尾的最大子序列和M[1]就是a1，
// 然后从下标2开始递推：M(i) = ai + max { M(j) | aj < ai }
// 最后求：max { M(i) }，就是最大子序列和。 
int main() {
	int group,num,max;
	int a[5001], M[5001]; //最多5000个数
	int i,j,k;

	scanf("%d",&group);
	for(i=0;i<group;i++) {
		scanf("%d",&num);

		M[0]=a[0]=0; // 实际输入数从下标1开始保存；下标0用做边界条件，以简化计算

		for(j=1;j<=num;j++) 
			scanf("%d",&a[j]);
		for(j=0;j<=num;j++)  
			M[j]=0; 
		M[1]=a[1];
		for(j=2;j<=num;j++)	{ // 递推计算a2~an的最大子序列和
			max=0;
			for(k=1;k<j;k++) { 
				if(a[k] < a[j] && max < M[k]) // 找当前元素之前的，并且当前元素加入后仍然保持递增的，最大子序列和
					max=M[k];
			}
			M[j]=max+a[j];
		}

		max=0;
		for(j=1;j<=num;j++) 
			if(M[j]>max) max=M[j];
		printf("case #%d:\n%d\n",i,max);
	}

	return 0;
}