#include<stdio.h>
#include<stdlib.h>
int cmp_price(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}

int main()
{
	int group,price[100000],count, total;
	char order;
	char line[100] = { 0 };
	int start; 
	int i,j,v;
	scanf("%d",&group);
	for(i=0;i<group;i++)
	{
		scanf("%d ",&total);

		start = count=0;
		printf("case #%d:\n", i);
		for (j = 0; j < total; j++) {
			gets(line);

			sscanf(line, "%c %d",&order, &v);
			if (order == 'B') {
				price[count++] = v; // 始终将读取的价格保存在数组最后位置
				// 每次读取一个B操作后，都要进行排序。
				qsort(price + start, count - start, sizeof(int), cmp_price); 
			}
			else if (order == 'G') { 
				// 排序后，G操作直接取price数组第一个元素即可。用start记录price数组中的有效元素（还没被G走）的位置，每取一次就后移一个位置
				// qsort排序也忽略已经被取走的元素，从price+start位置开始排序。
				printf("%d\n", price[start]);
				start++;
			}
		}
		
	}
	return 0;
}