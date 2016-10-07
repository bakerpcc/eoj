#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ����������������a[lefft, right]���з���������������a��ǰk��Ԫ�أ���a[left..left+k-1]��
// ������a�е�k����СԪ�ء�
void partition(int a[], int left, int right, int k) {
  // �����a����ѡһ��Ԫ�ء�����left..right-1�������һ��λ�á�
	int randNum = left + (rand() % (right - left + 1)); 
	
	// ������鵽��Ԫ��������������Ԫ��a[left]����
	int t = a[randNum];
	a[randNum] = a[left];
	a[left] = t;

  // ��a[left]Ϊ��׼����ǰ�����ѡȡ������Ԫ�أ�ʵ�ʳ鵽��һ��������Ҫ������������з�����
  // �����Ľ��������Ԫ�ش��߼��Ϸֳ������飬�����<=�����ȡԪ�صļ��ϣ��ұ���>�����ȡԪ�صļ���
  // ���磺����a={ 6,5,4,3,9,8,2,1 }������鵽��randNum=1����a[1]=5���������д��뽫a[1]���������
  // a���{ 5,6,4,3,9,8,2,1 }��ô�������ѭ������ִ�У�a������{ 5,1,4,3,9,8,2,6 }��{ 5,1,4,3,2,8,9,6 }��
  // ������� { 2,1,4,3,5,8,9,6 }��ѭ��������j=4, ��a[j]Ϊ�ָ��(a[j]=5)����߶�<=5, �ұ߶�>5��
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

// ��Ϊ��Ҫ�ҳ�ǰk��Ԫ�أ�������j=k���ʾa[left..left+j-1]�иպ��������е�ǰk����СԪ�ء�
// ���j>k�����ʾ����������Ԫ�ر���Ҫ��k��Ԫ�ض࣬����༯�ϣ���a[left..left+j-1]�����з������õݹ�д�ܼ�
// ���j<k�������Ԫ�ز���k������Ҫ���ұ߼��Ϸ�����
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

// partitionִ�����a��ǰk����������С��ǰk��������k��Ԫ��������ģ�������Ҫ��Ҫ��ǰk��Ԫ������
// ���ֻҪ�ҳ�ǰk��Ԫ�أ�����������
// ����Ϊ�β�ֱ��qsort�����ǰk��ֵ����Ϊ���a����ܴ󣬶�k��С����a��100���Ԫ�أ���kֻ��10����
// ��������ʱ�临�Ӷ�ΪO(n * log n), ��100��*30��Լ3000���ѭ���ͽ�������ʵ��ֻ��Ҫǰ30��ֵ������Ľ�100��������û�б�Ҫִ���ˡ�
	qsort(a, k, sizeof(int), comp);

	for(int i = 0; i < k; i++)
		if (i == 0)
			printf("%d", a[i]);
		else
	    	printf(" %d", a[i]);
	printf("\n");
}
