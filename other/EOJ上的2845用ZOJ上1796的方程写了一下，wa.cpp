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
                                p=1;//p��ʾ��������x���ٴ���Ϊ1��֮������ɨ�赽^��p��Ϊ2.��Ϊ�����pΪ��ʼֵ0�����䡣
                        } else if (isdigit(str[i])) {
                                r=r*10+str[i]-'0';//r��ʾx֮ǰ��ϵ����
								//printf("r:%d\np:%d\n",r,p);
                                f=1;//f������ʾx֮ǰ�Ƿ����ϵ����flag�������������У�if (!f),˵��fΪ��ʼֵ0����ǿ�Ƹ�ϵ��1.
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
