#include<stdio.h>
#include<string.h>
int main()
{
    int ale,ble,n,fl;
    char a[100000],b[100000];
    while(scanf("%s%s",a,b)!=EOF){
        ale=strlen(a);
        ble=strlen(b);
        n=0;
        fl=0;
        for(int i=0;i<ble;i++){
            if(b[i]==a[n]){
                n++;
                if(n==ale){
                    fl=1;
                    break;
                }
            }
        }
        if(fl){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}