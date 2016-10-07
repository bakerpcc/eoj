#include<stdio.h>
char *months[]={"SU","MO","TU","WE","TH","FR","SA"}; 
void printFebs(int year);//�ú�����ӡ2008����Ҫ���2�µ�������
void printCalendar(int firstDay, int daysInMonth);
int main()
{
	int n;
	while(scanf("%d",&n) == 1)
		printFebs(n);
}
void printFebs(int year)
{
	int cur=2008;//��ǰ���Ϊ2008�ꡣ
	int firstDay=5; //��ʾcur��ǰ��ӡ����ݵ�2��1��Ϊ�ܼ���������0��ʾ����һ�������ö�Ӧ���֡�2008.2.1Ϊ���壬��Ŀ���ġ�
	int daysInMonth = 28; // ���¹�������
	int daysInYear = 365; //���깲������
	int totalDays= 0;
	while (cur < year) 
	{
		if((cur%4==0)&&(cur%100!=0)||(cur%400)==0)
			daysInYear=366;
		else
			daysInYear=365;

		totalDays += daysInYear;
		// printCalendar(firstDay, daysInMonth); // ��ӡĳ��������ͨ�ú���������Ϊĳ�µ�һ��Ϊ�ܼ�������һ�������졣
		cur++;
		//firstDay=(firstDay + daysInYear) % 7; // ��һ���������������2��1�����ܼ���Ȼ��ȡ7��ģ���ܵó���һ��2��1�����ܼ�
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
		printf("%3s", months[i]); // ��ӡ������ͷ
	printf("\n");
	// ��ӡ1��ǰ�Ŀհס�����2008-02-01�����壬��Ҫ�ȴ�ӡ15���հ�
	for (i = 0; i < firstDay; i++) printf("%3s", " "); 
	for (i = 1; i <= daysInMonth; i++) {		
		printf("%3d", i);
		if ((i + firstDay ) % 7 == 0) printf("\n");
	}
	printf("\n\n");
}