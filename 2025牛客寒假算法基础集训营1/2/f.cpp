#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    while(n--) {
        long long l, r;
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",r-l+1);
    }
    return 0;
}