#include <stdio.h>
#include <string.h>
#define N 50
int max(int a,int b) {  return a>b ? a : b;  }
int fenceLen(char* s)
{ char*p=s;
  if (!*p) return 0; //���ַ����ĳ���=0���ݹ���ֹ����
  while (*(p+1)&&*p!=*(p+1)) p++; //���㿪ͷ��һ�εĳ���
  return max(p+1-s,fenceLen(p+1)); //�Ƚϵ�һ���������ַ�����ʾΧ���ĳ���
}
//����Ҫ���ݹ�˼�롣return max(p+1-s,fenceLen(p+1))��ʵ�Ǵ����һ����ǰ�Ƚϵġ�
//���缸�εĳ��ȷֱ�Ϊ5,1,3,4���ͻ᣺3,4->4,1,4->4,5,4->5�����ս��Ϊ5��������
int main()
{ char s[N+1];
  gets(s);
  printf("%d\n",fenceLen(s));
  return 0;
}
