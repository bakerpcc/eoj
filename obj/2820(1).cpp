#include<stdio.h>
#include<string.h>

int main()
{
	int i=0,j=0,n,max=0;
	//char str[50];
	
	char str[50] = {0}; // "|||-||--|--|---|-||-|-|-|--||---||-||-||-|--||";

	scanf("%s", str);

	n = strlen(str);

	int status = 0;	// 1, "|"; 2, "-", 0Ϊ��ʼ״̬


	int currentLength = 0;

	for(i = 0;i < n; i++)
	{
		if (status == 0)	
		{
			if ( str[i] == '|')
			{
				status = 1;
			}
			else if (str[i] == '-')
			{
				status = 2;
			}
			currentLength = 1;
		}
		else if (status == 1)
		{
			if (str[i] == '-')
			{
				status = 2;
				currentLength ++;
			}
			else  
			{
				status = 1;
				currentLength = 1;
			}
		}
		else if (status == 2)
		{
			if ( str[i] == '|')
			{
				status = 1;
				currentLength ++;
			}
			else
			{
				status = 2;
				currentLength = 1;
			}
		}

		if (max < currentLength)
		{
			max = currentLength;
		}

	}
   
	printf("%d",max);
	return 0;
}