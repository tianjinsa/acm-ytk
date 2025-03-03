#include<stdio.h>

int main()
{
    char a[10001],ch;
    int i=0,j;
    while(scanf("%c",&ch)!=EOF&&ch!='\n'){
        if(ch!=' '){
            a[i]=ch;
            i++;
        }
    }
    j=i;
    a[i]='\0';
    i=0;
    while(scanf("%c",&ch)!=EOF&&ch!='\n'){
        if(ch!=' '){
            if(i>=j||(ch!=a[i]&&ch!=a[i]-32&&ch!=a[i]+32)){
                printf("NO");
                return 0;
            }
            i++;
        }
    }
    if(i!=j){
        printf("NO");
        return 0;
    }
    printf("YES");
    return 0;
}