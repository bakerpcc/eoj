
#include <stdio.h>



#define NUM 101

#define MAXW 100001



int mat[NUM][NUM];

int record[NUM][NUM];



int init();

void flyodpath(int );



int main()

{

	int count;

	count=init();

	flyodpath(count);

	return 0;

}



int init()

{

	int count,side,i,j,temp,k;

	scanf("%d%d",&count,&side);

	for(i=0;i<=count;i++)

		for(j=0;j<=count;j++)

		{

			if(i==j)

				mat[i][j]=0;

			else

				mat[i][j]=MAXW;

			record[i][j]=0;

		}

	for(i=0;i<side;i++)

	{

		scanf("%d%d%d",&j,&temp,&k);

		if(mat[j][temp]==k)

		{

			record[j][temp]++;

			continue;

		}

		mat[j][temp]=k;

		record[j][temp]=1;

	}

	return count;

}



void flyodpath(int count)

{

	int i,j,k,tag=0;

	for(k=1;k<=count;k++)

		for(i=1;i<=count;i++)

			for(j=1;j<=count;j++)

			{

				if(i!=j&&j!=k&&i!=k)

				{

					if(mat[i][k]+mat[k][j]<mat[i][j])

					{

						mat[i][j]=mat[i][k]+mat[k][j];

						record[i][j]=record[i][k]*record[k][j];

						if(i==1&&j==count)

							tag=1;

					}

					else if(mat[i][j]==mat[i][k]+mat[k][j])

					{

						record[i][j]+=record[i][k]*record[k][j];//相à等台?则ò加ó上?去ǎ?

						if(i==1&&j==count)

							tag=1;

					}

						

				}	

			}

			if(tag==0)

				printf("-1 0\n");

			else

				printf("%d %d\n",mat[1][count],record[1][count]);

			return;

}
