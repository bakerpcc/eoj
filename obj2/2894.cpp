#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char s[81],**a,*p,rec;
	//row[81]���ڴ��s�е�ÿ���ַ�Ӧ�ڵ��кš�max��¼����кţ�min��¼��С�к�
	int row[81], max, min; 
	int len,i,j;
	while(gets(s))
	{
		len=strlen(s);
		p=s;
		min = max = 0;
		row[0] = 0;
		for (i = 1; i < len; i++) {
			if (s[i] - s[i-1] == 0)
				row[i] = row[i-1];
			else if (s[i] - s[i-1] > 0)
				row[i] = row[i-1] + 1;
			else
				row[i] = row[i-1] - 1;

			if (min > row[i])
				min = row[i];
			if (max < row[i])
				max = row[i];
		}

		for (i = max; i >= min; i--) {
			for (j = 0; j < len; j++) {
				if (row[j] == i) 
					printf("%c", s[j]);
				else
					printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}