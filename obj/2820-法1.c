#include <stdio.h>
#include <string.h>
#define N 50

int fenceLen(char* s)
{ int i,n=strlen(s),m=0,len=1;
  if (n<2) return n;//������<2�����
  for (i=1;i<n;i++)
    if (s[i]!=s[i-1]) len++;
    else { if (len>m) m=len; len=1; }//��һ���ַ���ǰһ���ַ���ͬʱ����ʾ�µ�һ�ο�ʼ
  if (len>m) m=len; //�������һ��(�����һ������ķ��ţ���|����-����������һ�䣬�����롰|-|-�����������ģ�lenû�б���ֵ��m��������ʼ��Ϊ0��m=0����
  return m;
}
 
int main()
{ char s[N+1];  gets(s);
  printf("%d\n",fenceLen(s));
  return 0;
}
