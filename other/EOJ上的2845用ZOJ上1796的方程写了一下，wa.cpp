#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#include<math.h>

char str[128];
int c[4];

int main() {
        int sign,i,r,p,sign1,f;
		char cc='a';
        while(scanf("%s",str)!=EOF) {
				sign=sign1=1;
                memset(c,0,sizeof(c));
                for(f=i=r=p=0;str[i];i++) {
                        if (str[i]=='=') {
                                if (p && r==0) r=1;
                                c[p]+=sign*sign1*r;
								//printf("'=':cp:%d\n",c[p]);
                                sign1=-1;
                                r=p=f=0,sign=1;
                        } else if (str[i]=='+') {
                                c[p]+=sign*sign1*r;
								//printf("'+':cp:%d\n",c[p]);
                                sign=1,r=p=f=0;
                        } else if (str[i]=='-') {
                                c[p]+=sign*sign1*r;
								//printf("'-':cp:%d\n",c[p]);
                                sign=-1,r=p=f=0;
                        } else if ((str[i]>='a')&&(str[i]<='z')) {
								cc=str[i];
                                if (!f) r=1;
								if(str[i+1]==NULL) f=1;
								//printf("---------\n");
                                p=1;//p表示次数。有x至少次数为1，之后若再扫描到^则p变为2.若为常数项，p为初始值0，不变。
                        } else if (isdigit(str[i])) {
                                r=r*10+str[i]-'0';//r表示x之前的系数。
								//printf("r:%d\np:%d\n",r,p);
                                f=1;//f用来表示x之前是否存在系数（flag）。返回上两行，if (!f),说明f为初始值0，故强制赋系数1.
                        }
                }
                if (f) c[p]+=sign*sign1*r;

				//printf("%d %d %d\n",c[0],c[1],c[2]);

                //assert(c[2]!=0);
                /*if (c[1]*c[1]>=4*c[0]*c[2]) {
                        double d=sqrt(1.0*(c[1]*c[1]-4*c[0]*c[2]));
                        printf("%.2lf %.2lf\n",(-c[1]-d)/2/c[2]+1e-6,(-c[1]+d)/2/c[2]+1e-6);
                } else puts("No Solution");*/
				printf("%c=%.3f\n",cc,-(1.0*c[0])/c[1]);
        }
        return 0;
}
