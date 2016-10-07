#include <stdio.h>
#include <string.h>
#define N 50
int max(int a,int b) {  return a>b ? a : b;  }
int fenceLen(char* s)
{ char*p=s;
  if (!*p) return 0; //空字符串的长度=0，递归终止条件
  while (*(p+1)&&*p!=*(p+1)) p++; //计算开头第一段的长度
  return max(p+1-s,fenceLen(p+1)); //比较第一段与余下字符串表示围栏的长度
}
//这里要懂递归思想。return max(p+1-s,fenceLen(p+1))其实是从最后一段往前比较的。
//比如几段的长度分别为5,1,3,4，就会：3,4->4,1,4->4,5,4->5，最终结果为5，这样。
int main()
{ char s[N+1];
  gets(s);
  printf("%d\n",fenceLen(s));
  return 0;
}
