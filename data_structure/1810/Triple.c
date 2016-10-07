#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

// �ýṹ���ʾϡ����Ԫ��
typedef struct
{
	int i, j;	// ���±�,���±�
	ElemType e; // ����Ԫ��ֵ
}
Triple;

typedef struct
{
	Triple *data; 		// ����Ԫ��Ԫ���,data�������붯̬����ռ�
	int mu, nu, tu;		// ����������������ͷ���Ԫ����
} Matrix;

// ���������ض�ȡ��ϡ�����
Matrix * CreateMatrix(int m, int n, int t)
{
	Matrix *M = (Matrix *)malloc(sizeof(Matrix));
	M->mu = m;
	M->nu = n;
	M->tu = t;
	M->data = (Triple *)malloc(t * sizeof(Triple)); // ��̬����tu+1��Triple��Ԫ��

	return M;
}

void ReadMatrix(Matrix *M)
{
	int i;

	for (i = 0; i < M->tu; i++)
	{
		scanf("%d%d%d", &(M->data[i].i), &(M->data[i].j), &(M->data[i].e));
	}
}

// ����ϡ�����M������Ԫ���ÿ�
void DestroyMatrix(Matrix *M)
{
	free(M->data);
	free(M);
}

// ���ϡ�����M
void PrintMatrix(Matrix *M)
{
	int i;
	for (i = 0; i < M->tu; i++)
		printf("%d %d %d\n", M->data[i].i, M->data[i].j, M->data[i].e);
}

// ��ϡ�����M��ת�þ���T����ͨ�㷨
int TransposeMatrix(Matrix *M, Matrix *T)
{
	int p, q, col;

	if (M->tu > 0)
	{
		q = 0;
		for (col = 0; col < M->nu; ++col) //�Ƚ���ת������
		for (p = 0; p < M->tu; ++p)	//�ٽ���ת������
		if (M->data[p].j == col)
		{
			T->data[q].i = M->data[p].j;
			T->data[q].j = M->data[p].i;
			T->data[q].e = M->data[p].e;
			++q;
		}
	}
	return 0;
}

// ������ϡ�����M��ת�þ���T�����ݽṹ������Ӧ�����㷨������
int FastTransposeMatrix(Matrix *M, Matrix *T)
{
	int p, q, t, col, tmp, *num, *cpot;
	num = (int *)malloc((M->nu)*sizeof(int));	// ��������
	cpot = (int *)malloc((M->nu)*sizeof(int));	// ��������

	if (T->tu > 0)
	{
		for (col = 0; col < M->nu; ++col)
			num[col] = 0; // ���ֵ
		for (t = 0; t < M->tu; ++t) // ��M��ÿһ�к�����Ԫ�ظ���
		{
			tmp = M->data[t].j;
			++num[tmp];
		}
		cpot[0] = 0;
		// ���col���е�һ������Ԫ��(*T).data�е����
		for (col = 1; col < M->nu; ++col)
			cpot[col] = cpot[col - 1] + num[col - 1];
		for (p = 0; p < M->tu; ++p)
		{
			col = M->data[p].j;
			q = cpot[col];
			T->data[q].i = M->data[p].j;
			T->data[q].j = M->data[p].i;
			T->data[q].e = M->data[p].e;
			++cpot[col];
		}
	}

	free(num);
	free(cpot);

	return 0;
}

int main()
{
	int m, n, t;
	Matrix *A, *B;
	scanf("%d%d%d", &m, &n, &t);
	A = CreateMatrix(m, n, t);
	B = CreateMatrix(n, m, t);

	ReadMatrix(A);

	FastTransposeMatrix(A, B);
	PrintMatrix(B);

	// TransposeMatrix(A, B);
	// PrintMatrix(A, B);

	DestroyMatrix(A);
	DestroyMatrix(B);

	return 0;
}
