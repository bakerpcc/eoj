#include<stdio.h>
#include<math.h>
struct stu
{char no[11];
int score;}
;
int main()
{int group,i,sum=0;
struct stu a[100];
double aver,dev,sumd=0;
scanf("%d",&group);
for(i=0;i<group;i++){
 scanf("%s %d",a[i].no,&a[i].score);
  sum=sum+a[i].score;
 }
 
aver=(1.0*sum)/(1.0*group);
for(i=0;i<group;i++)
 sumd=sumd+(a[i].score-aver)*(a[i].score-aver);
dev=sqrt(sumd/(group-1));
printf("%.2f %.2f\n",aver,dev);
return 0;
}