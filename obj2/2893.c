#include<stdio.h>
#include<string.h>

int gcd(int m,int n)
{
	if(m%n==0) return n;
	else gcd(n,m%n);
}

int main()
{
	int group,count,size;
	int i,c1,n; 
	char s[500],*p,c,t[2];
	scanf("%d ",&group);
	for(i=0;i<group;i++)
	{
		size = count = 0;
		gets(s);
		p=s;
		while(*p!=NULL){
			size += 8; // ÿ���ֽ�8λ
			for (c1 = 0; c1 < 8; c1++) // �жϸ��ֽ��ж��ٸ�1����0λѭ����7λ
				if ((1<<c1) & *p) // 1����clλ�պ��Ǹ�λΪ1������λΪ0�����룬�뵱ǰ�ַ�*p��λ&���������*p�ĸ�λΪ1�������Ȼ>0,����=0
					count++;
			p++;
		}

		n=gcd(size,count);
		printf("%d/%d\n",count/n,size/n);
	}
	return 0;
}
