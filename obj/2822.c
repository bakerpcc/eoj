// ������ʾ�������һ������debugger��memory��������ʾ����ʽ
#include <stdio.h>
#include <stdlib.h>   // atoi
#include <string.h>   //atof,gets
#define N 80
int main()
{ int i;  char s[N],buf[N];
  while(scanf("%s",s)==1) //����1�У�ֱ������
  {   for (i=0;s[i];i++) if (s[i]=='.') break; //�ж��Ƿ�С����
      if (s[i])  // ��С������ַ�����ʾһ��������
      {  double f=atof(s); //�ַ�����ʾ�ĸ�����ת��Ϊһ��������
          for (i=0;i<sizeof(double);i++) //���������������ÿ���ֽ�ֵ
                               //��ͬ���뻷���е��ֽ������ܲ�ͬ
                               //�ֽڵĴ��˳��Ҳ���ܲ�ͬ,�����г����CPU��ϵ�ṹ�й�
                               //�磺Intel CPU�Ĵ��˳��Ϊ�� ���ֽ�-->���ֽ� 
          printf("%02x ",((unsigned char*)&f)[i]); //��16���Ƹ�ʽ���&f��ʼ��ÿ���ֽڣ�һ�����һ���ֽ�
      }
      else  // ����С������ַ�����ʾһ������
      {   int d=atoi(s);   //�ַ�����ʾ������ת��Ϊһ������         
          for (i=0;i<sizeof(int);i++)
          printf("%02x ",((unsigned char*)&d)[i]);
      }
      printf("\n");
    }
   return 0;
}
