#include <stdio.h>
long long gcd(long long a,long long b)
{
    return (b==0)?a:gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
    return a*b/gcd(a,b);
}
int main()
{
    long long n,m,a,x;
    scanf("%lld",&n);
    while (n--)
    {
        scanf("%lld",&m);
        scanf("%lld",&a);
        x=a;
        m--;
        while (m--)
        {
            scanf("%lld",&a);
            x=lcm(x,a);
        }
        printf("%lld\n",x);
    }
    
    return 0;
}
