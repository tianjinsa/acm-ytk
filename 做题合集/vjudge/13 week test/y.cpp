#include<stdio.h>
#include<string.h>
int sss(char ch[],char x[],int a)
{
    int n=0;
    char *p;
    char temp[100];
    strcpy(temp,ch);
    while(p=strstr(temp,x)){
        n++;
        memset(p,1,a);
    }
    return n;
}
int main()
{
    int n,cn;
    scanf("%d",&n);
    char ch[100],x[100]={0};
    while(n--){
        if(x[0]!='\0'){
            printf("\n");
        }
        scanf("%s",ch);
        cn=strlen(ch);
        for(int i=1;i<=strlen(ch);i++){
            if(cn%i){
                continue;
            }
            for(int j=0;j<i;j++){
                x[j]=ch[j];
            }
            x[i]='\0';
            if(sss(ch,x,i)*i==cn){
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}