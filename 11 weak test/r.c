#include<stdio.h>
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
long long apls(int x,int y)//(下标，上标)
{
    long long z=1;
    for(int i=x;i>x-y;i--){
        z*=i;
    }
    return z;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        printf("%.2lf%%\n",derangement(a)*100.0/apls(a,a));
    }
    return 0;
}
