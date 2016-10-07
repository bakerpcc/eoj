#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

// 用结构体表示稀疏三元组
typedef struct
{
	int i, j;	// 行下标,列下标
	ElemType e; // 非零元素值
}
Triple;

typedef struct
{
	Triple *data; 		// 非零元三元组表,data根据输入动态分配空间
	int mu, nu, tu;		// 矩阵的行数、列数和非零元个数
} Matrix;

// 创建并返回读取的稀疏矩阵
Matrix * CreateMatrix(int m, int n, int t)
{
	Matrix *M = (Matrix *)malloc(sizeof(Matrix));
	M->mu = m;
	M->nu = n;
	M->tu = t;
	M->data = (Triple *)malloc(t * sizeof(Triple)); // 动态分配tu+1个Triple三元组

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

// 销毁稀疏矩阵M，所有元素置空
void DestroyMatrix(Matrix *M)
{
	free(M->data);
	free(M);
}

// 输出稀疏矩阵M
void PrintMatrix(Matrix *M)
{
	int i;
	for (i = 0; i < M->tu; i++)
		printf("%d %d %d\n", M->data[i].i, M->data[i].j, M->data[i].e);
}

// 求稀疏矩阵M的转置矩阵T。普通算法
int TransposeMatrix(Matrix *M, Matrix *T)
{
	int p, q, col;

	if (M->tu > 0)
	{
		q = 0;
		for (col = 0; col < M->nu; ++col) //先将列转换成行
		for (p = 0; p < M->tu; ++p)	//再将行转换成列
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

// 快速求稀疏矩阵M的转置矩阵T。数据结构的书上应该有算法的描述
int FastTransposeMatrix(Matrix *M, Matrix *T)
{
	int p, q, t, col, tmp, *num, *cpot;
	num = (int *)malloc((M->nu)*sizeof(int));	// 生成数组
	cpot = (int *)malloc((M->nu)*sizeof(int));	// 生成数组

	if (T->tu > 0)
	{
		for (col = 0; col < M->nu; ++col)
			num[col] = 0; // 设初值
		for (t = 0; t < M->tu; ++t) // 求M中每一列含非零元素个数
		{
			tmp = M->data[t].j;
			++num[tmp];
		}
		cpot[0] = 0;
		// 求第col列中第一个非零元在(*T).data中的序号
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
