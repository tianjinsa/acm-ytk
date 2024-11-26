#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char a[10001],b[10001];
    int s,xx=0;
    fgets(a,10001,stdin);
    s=strlen(a);
    for(int i=0;i<s;i++){
        if('0'<=a[i]&&a[i]<='9'){
            b[xx++]=a[i];
        }
        else if(xx){
            b[xx]='\0';
            printf("%d\n",atoi(b));
            xx=0;
        }
    }
    if(xx){
        b[xx]='\0';
        printf("%d\n",atoi(b));
    }
    return 0;
}