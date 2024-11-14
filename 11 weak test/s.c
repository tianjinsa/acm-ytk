#include <stdio.h>
long long cpls(int n,int k)//(下标，上标)
{
    if(k>n-k)k=n-k;
    long long xx=1;
    for(int i=0;i<k;++i){
        xx*=(n-i);
        xx/=(i+1);
    }
    return xx;
}
long long derangement(int n)
{
    long long dp[n+1];
    dp[2]=1;
    dp[3]=2;
    for(int i=4;i<=n;i++){
        dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
    }
    return dp[n];
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%lld\n",cpls(a,b)*derangement(b));
    }
    return 0;
}