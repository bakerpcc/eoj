#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int m[13][2]={0,0,
              31,31,
              28,29,
              31,31,
              30,30,
              31,31,
              30,30,
              31,31,
              31,31,
              30,30,
              31,31,
              30,30,
              31,31};

int leap(int y)
{
        return (y%4==0&&y%100!=0)||(y%400==0);
}

int day(int Y,int M,int D)
{
        int k=0,i,d;
        if(leap(Y))
                k=1;
        for(d=0,i=1;i<M;i++)
                d+=m[i][k];
        d+=D;
        return d;
}

int main()
{
        int Y1,M1,D1,Y2,M2,D2,i,d1,d2;
        while(scanf("%4d%2d%2d",&Y1,&M1,&D1)!=EOF)
        {
                scanf("%4d%2d%2d",&Y2,&M2,&D2);
                d1=day(Y1,M1,D1);
                d2=day(Y2,M2,D2);
                for(i=0;i<Y1;i++)
                        if(leap(i))
                                d1+=366;
                        else
                                d1+=365;
                for(i=0;i<Y2;i++)
                        if(leap(i))
                                d2+=366;
                        else
                                d2+=365;
                printf("%d\n",(int)abs(d1-d2)+1);
        }
        return 0;
}