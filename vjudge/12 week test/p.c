#include<stdio.h>

int main()
{
    long long n;
    while(scanf("%lld",&n)&&n){
        printf("%lld\n",n%9==0?9:n%9);
    }
    return 0;
}
