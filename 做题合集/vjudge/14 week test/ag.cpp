#include<bits/stdc++.h>
//using namespace std;
int main() {
    long long dp[1001]={0};
    dp[0]=dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=1000;i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%lld\n",dp[n]);
    }
    return 0;
}