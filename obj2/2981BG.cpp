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
				price[count++] = v; // ʼ�ս���ȡ�ļ۸񱣴����������λ��
				// ÿ�ζ�ȡһ��B�����󣬶�Ҫ��������
				qsort(price + start, count - start, sizeof(int), cmp_price); 
			}
			else if (order == 'G') { 
				// �����G����ֱ��ȡprice�����һ��Ԫ�ؼ��ɡ���start��¼price�����е���ЧԪ�أ���û��G�ߣ���λ�ã�ÿȡһ�ξͺ���һ��λ��
				// qsort����Ҳ�����Ѿ���ȡ�ߵ�Ԫ�أ���price+startλ�ÿ�ʼ����
				printf("%d\n", price[start]);
				start++;
			}
		}
		
	}
	return 0;
}