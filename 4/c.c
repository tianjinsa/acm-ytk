#include<stdio.h>
#include<string.h>
int main()
{
    long long n;
    char tt[1010];
    while(scanf("%s",tt)!=EOF){
        if(tt[0]=='0'){
            break;
        }
        n=0;
        for(int i=0;tt[i]!=0;i++){
            n+=tt[i]-'0';
        }
        n%=9;
        if(n==0){
            printf("9\n");
        }
        else{
            printf("%lld\n",n);
        }
    }
    return 0;
}