#include <stdio.h>
#include <ctype.h>

#define N 80

void readeq(char* s, char* var, int* co, int* val)
{
    int left=1; //目前处理的是=的左边

    while (*s) //处理至字符串结束

    {  int sign=1,a=0; //系数或常数的符号，缺省为+ 。读取整数值的初始值设为0。

       if (*s=='=' ) s++,left=0; //之后处理的是=的右边

       if (*s=='+' ) s++; else if (*s=='-') sign=-1,s++; //符号处理

       while (isdigit(*s)) {  a=a*10+*s-'0'; s++; } //是数字的话，计算连续数字表示的数值

//不是字母的话，表示是一个常数项，（1）
//否则后面应该是一个变量名，表示是一个变量项，（2）
//拿27x+18来说，18是（1），27x是（2）

       if (!isalpha(*s)) *val+=a*sign*(left?-1:1); //累加常数项（设将常数项移到=右边后的符号）

       //如果变量名前面没有出现数字的话，表示该项的系数是1
      //记录变量名，以备输出之用
   //累加变量的系数项（设将变量项移到=左边后的符号）

       else  { if (a==0) a=1; *var=*s++; *co+=a*sign*(left?1:-1); } 
    //这里的*var=*s++的意思是*var=*s;s++;
	
   }
}

int main()
{ 
  char var;      //变量名
  int co=0,val=0; //co是变量的系数之和，val是常量的和

  char s[N]; scanf("%s",s);  //读入方程式

 //从方程式中获取变量名、变量的系数之和、常量的和
 //变量的系数之和是所有变量项移到=左边后的值
 //常量的和是所有常量项移到=右边后的值

  readeq(s,&var,&co,&val);   

  // 方程的解：变量名=常量的和/变量的系数之和

  printf("%c=%.3f\n",var,1.0*val/co);  //这里的除法运算不能是整除

  return 0;
}
