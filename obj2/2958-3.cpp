#include<stdio.h>
#include<stdlib.h>

// ���Ի���˼·���ٶ�����Ϊa1,a2,...an�� ������M[i]��ʾ��ai��β�����������;
// ��ʼ��ʱ�������趨M[i] = 0, ��ʾ��������кͶ���0��
// ��a1��β����������к�M[1]����a1��
// Ȼ����±�2��ʼ���ƣ�M(i) = ai + max { M(j) | aj < ai }
// �����max { M(i) }��������������к͡� 
int main() {
	int group,num,max;
	int a[5001], M[5001]; //���5000����
	int i,j,k;

	scanf("%d",&group);
	for(i=0;i<group;i++) {
		scanf("%d",&num);

		M[0]=a[0]=0; // ʵ�����������±�1��ʼ���棻�±�0�����߽��������Լ򻯼���

		for(j=1;j<=num;j++) 
			scanf("%d",&a[j]);
		for(j=0;j<=num;j++)  
			M[j]=0; 
		M[1]=a[1];
		for(j=2;j<=num;j++)	{ // ���Ƽ���a2~an����������к�
			max=0;
			for(k=1;k<j;k++) { 
				if(a[k] < a[j] && max < M[k]) // �ҵ�ǰԪ��֮ǰ�ģ����ҵ�ǰԪ�ؼ������Ȼ���ֵ����ģ���������к�
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