#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 分区函数：对数组a[lefft, right]进行分区，分区结束后，a的前k个元素（即a[left..left+k-1]）
// 是数组a中的k个最小元素。
void partition(int a[], int left, int right, int k) {
  // 随机从a中挑选一个元素。即从left..right-1中随机抽一个位置。
	int randNum = left + (rand() % (right - left + 1)); 
	
	// 将随机抽到的元素与数组最左侧的元素a[left]交换
	int t = a[randNum];
	a[randNum] = a[left];
	a[left] = t;

  // 以a[left]为基准（即前面随机选取的数组元素，实际抽到哪一个并不重要），对数组进行分区，
  // 分区的结果是数组元素从逻辑上分成了两组，左边是<=随机抽取元素的集合，右边是>随机抽取元素的集合
  // 例如：数组a={ 6,5,4,3,9,8,2,1 }，随机抽到的randNum=1，即a[1]=5，上面三行代码将a[1]换至最左边
  // a变成{ 5,6,4,3,9,8,2,1 }那么下面这段循环代码执行，a将会是{ 5,1,4,3,9,8,2,6 }，{ 5,1,4,3,2,8,9,6 }，
  // 最后结果是 { 2,1,4,3,5,8,9,6 }，循环结束后j=4, 以a[j]为分割点(a[j]=5)，左边都<=5, 右边都>5。
	int i = left;
	int j = right;
	int key = a[left];
	while(i <= j) {
		if (a[i] <= key)
			i++;
		else	{
			int t = a[j];
			a[j] = a[i];
			a[i] = t;

			j--;
		}
	}

	a[left] = a[j];
	a[j] = key;

// 因为需要找出前k个元素，因此如果j=k则表示a[left..left+j-1]中刚好是数组中的前k个最小元素。
// 如果j>k，则表示数组中左侧的元素比需要的k个元素多，对左侧集合（即a[left..left+j-1]）进行分区。用递归写很简单
// 如果j<k，则左侧元素不够k个，需要对右边集合分区。
	if (j == k) 
		return;
	else if (j > k)
		partition(a, left, j - 1, k);
	else
	  partition(a, j + 1, right, k);
}

int comp ( const void *a, const void *b ) {
	return * ( int * ) a - * ( int * ) b;
}

int main() {
	int n, k;
	int *a;

	scanf("%d%d", &n, &k);
	a = (int *)malloc(n * sizeof(int));

	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	srand(time(NULL));
	partition(a, 0, n - 1, k - 1);

// partition执行完后，a中前k个数虽是最小的前k个，但这k个元素是无序的，按本题要求还要对前k个元素排序。
// 如果只要找出前k个元素，就无需排序。
// 本题为何不直接qsort后输出前k个值？因为如果a数组很大，而k很小，如a有100万个元素，而k只有10个，
// 快速排序时间复杂度为O(n * log n), 即100万*30，约3000万次循环和交换。而实际只需要前30个值。后面的近100万个排序就没有必要执行了。
	qsort(a, k, sizeof(int), comp);

	for(int i = 0; i < k; i++)
		if (i == 0)
			printf("%d", a[i]);
		else
	    	printf(" %d", a[i]);
	printf("\n");
}
