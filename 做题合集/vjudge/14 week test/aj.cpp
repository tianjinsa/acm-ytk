#include<bits/stdc++.h>
//using namespace std;
void derangement(long long dp[],int n)//打表打到n
{
    dp[2]=1;
    dp[3]=2;
    for(int i=4;i<=n;i++){
        dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
    }
}
int main()
{
    long long dp[21];
    derangement(dp,20);
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%lld\n",dp[n]);
    }
    return 0;
}