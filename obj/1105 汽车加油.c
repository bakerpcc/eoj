#include<stdio.h>
int main()
{
 int fuel,station,fuel_per[1024];
 int i,j,sum,count,k=0;
 scanf("%d %d",&fuel,&station);

 count=0;sum=fuel;
 for(i=0;i<=station;i++)
   scanf("%d",&fuel_per[i]);
 for(i=0;i<=station;i++){
	if(fuel<fuel_per[i]) {printf("No Solution!\n");break;}
   else if(sum<fuel_per[i]) {sum=fuel;count++;}
   sum-=fuel_per[i];
   }
 if(i==station+1) printf("%d\n",count);

 return 0;
}

