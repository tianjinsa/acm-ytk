#include<bits/stdc++.h>
//using namespace std;
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
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF){
        printf("%lld %lld\n",gcd(a,b),lcm(a,b));
    }
    return 0;
}