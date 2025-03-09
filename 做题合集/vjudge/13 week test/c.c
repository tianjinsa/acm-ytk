#include<stdio.h>
#include<string.h>
int main()
{
    char ch[10005],ch1[10005],abc[]="0123456789ABCDEF";
    int a,n;
    scanf("%d",&n);
    getchar();
    while(n--){
        int xx=0,i=0,x;
        fgets(ch,10005,stdin);
        if(ch[strlen(ch)-1]=='\n'){
            ch[strlen(ch)-1]='\0';
        }
        if(strcmp(ch,"0")==0){
            printf("0\n");
            continue;
        }
        i=strlen(ch)-1;
        x=0;
        while(i>=-3){
            a=1;
            xx=0;
            for(int j=0;j>=-3&&i+j>=0;j--){
                if(ch[i+j]=='1'){
                    xx+=a;
                }
                a*=2;
            }
            ch1[x++]=abc[xx];
            i-=4;
        }
        ch1[x]='\0';
        a=0;
        for(int i=x-1;i>=0;i--){
            if(ch1[i]!='0'||a){
                printf("%c",ch1[i]);
                a=1;
            }
        }
        printf("\n");
    }
    return 0;
}