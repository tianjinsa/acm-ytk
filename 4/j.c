#include<stdio.h>
int main()
{
    long long a,i=0;
    while(scanf("%lld",&a)!=EOF)
    {
        printf("%lld\n\n",a*(a+1)/2);
        i=1;
    }
    return 0;
}