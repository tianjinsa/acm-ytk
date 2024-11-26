#include<stdio.h>
#include<string.h>
int key[205],co[205];
int main()
{
    int n,a;
    char ch[205],t[205];
    while(scanf("%d",&n)&&n){
        for(int i=0;i<n;i++){
            scanf("%d",&key[i]);
        }
        for(int i=0;i<n;i++){
            int d=1,cc=i;
            while((key[cc]-1)!=i){
                d++;
                cc=key[cc]-1;
            }
            co[i]=d;
        }
        while(scanf("%d",&a)&&a){
            getchar();
            memset(ch,' ',sizeof(ch));
            gets(ch);
            ch[strlen(ch)]=' ';
            for(int i=0;i<n;i++){
                int cc=i;
                for(int j=0;j<a%co[i];j++){
                    cc=key[cc]-1;
                }
                t[cc]=ch[i];
            }
            t[n]='\0';
            printf("%s\n",t);
        }
        printf("\n");
    }
    return 0;
}