#include<stdio.h>

int main()
{
    long long n;
    while(scanf("%lld",&n)!=EOF){
        printf("%lld\n",(n*n*n+5*n)/6+1);
    }
    return 0;
}