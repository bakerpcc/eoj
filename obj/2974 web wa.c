#include<stdio.h>
#include<string.h>

int cmp(char *s)
{
        if(strcmp(s,"the")==0 || strcmp(s,"a")==0 || strcmp(s,"an")==0 || strcmp(s,"of")==0 || strcmp(s,"for")==0 || strcmp(s,"and")==0)
                return 1;
        else return 0;
}
int main()
{
        int T,t;
        int l;
        int i,j;
        int num;
        char s[101];
        char word[101];
        scanf("%d",&T);getchar();
        for(t=0;t<T;t++)
        {
                num=0;
                i=0;
                j=0;
                gets(s);
                printf("case #%d:\n",t);
                l=strlen(s);
                
                while(s[i]!='\0')
                {

                        while(s[++i]==' ');
                        {
                                if(i==l)break;
                        }
                        while( s[i]>='A'&&s[i]<='Z' || s[i]>='a'&&s[i]<='z')
                        {
                                word[j++]=s[i];
                                i++;
                        }
                        word[j]='\0';
                        if( !cmp(word) )
                                num++;
                       j=0;
                }
                printf("%d\n",num);
        }
        
        return 0;
}
