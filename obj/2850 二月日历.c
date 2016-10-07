#include<stdio.h>
char *months[]={"SU","MO","TU","WE","TH","FR","SA"}; 
void printFebs(int year);//该函数打印2008年至要求的2月的日历。
void printCalendar(int firstDay, int daysInMonth);
int main()
{
	int n;
	while(scanf("%d",&n) == 1)
		printFebs(n);
}
void printFebs(int year)
{
	int cur=2008;//当前年份为2008年。
	int firstDay=5; //表示cur当前打印的年份的2月1日为周几，周日用0表示，周一至周六用对应数字。2008.2.1为周五，题目给的。
	int daysInMonth = 28; // 该月共多少天
	int daysInYear = 365; //该年共多少天
	int totalDays= 0;
	while (cur < year) 
	{
		if((cur%4==0)&&(cur%100!=0)||(cur%400)==0)
			daysInYear=366;
		else
			daysInYear=365;

		totalDays += daysInYear;
		// printCalendar(firstDay, daysInMonth); // 打印某月日历的通用函数，输入为某月第一天为周几，该月一共多少天。
		cur++;
		//firstDay=(firstDay + daysInYear) % 7; // 将一年的天数加上上年2月1日是周几，然后取7的模，能得出下一年2月1日是周几
	}

	if((year%4==0)&&(year%100!=0)||(year%400)==0)
		daysInMonth = 29;
	firstDay=(firstDay + totalDays) % 7;
	printCalendar(firstDay, daysInMonth); 
}

void printCalendar(int firstDay, int daysInMonth) 
{
	int i;
	for (i = 0; i < 7; i++)
		printf("%3s", months[i]); // 打印日历表头
	printf("\n");
	// 打印1号前的空白。比如2008-02-01是周五，就要先打印15个空白
	for (i = 0; i < firstDay; i++) printf("%3s", " "); 
	for (i = 1; i <= daysInMonth; i++) {		
		printf("%3d", i);
		if ((i + firstDay ) % 7 == 0) printf("\n");
	}
	printf("\n\n");
}