#include <stdio.h>
#include <string.h>
#define N 50

int fenceLen(char* s)
{ int i,n=strlen(s),m=0,len=1;
  if (n<2) return n;//处理长度<2的情况
  for (i=1;i<n;i++)
    if (s[i]!=s[i-1]) len++;
    else { if (len>m) m=len; len=1; }//当一个字符与前一个字符相同时，表示新的一段开始
  if (len>m) m=len; //处理最后一段(即最后一个输入的符号，“|”或“-”。少了这一句，若输入“|-|-”这样连续的，len没有被赋值给m，输出结果始终为0（m=0）。
  return m;
}
 
int main()
{ char s[N+1];  gets(s);
  printf("%d\n",fenceLen(s));
  return 0;
}
