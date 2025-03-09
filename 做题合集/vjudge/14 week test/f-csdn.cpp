#define N 1100
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int k[N],dp[N];
int n,m;
int main()
{
    while(scanf("%d",&n)&&n)
    {
        for(int i=0; i<n; i++)
            scanf("%d",&k[i]);
        scanf("%d",&m);
        if(m<5)//小于五元就什么也买不了
        {
            printf("%d\n",m);continue;
        }
        memset(dp,0,sizeof(dp));
        sort(k,k+n);
        for(int i=0; i<n-1; i++)//01背包问题
        {
            for(int j=m-5; j>=k[i]; j--)
            {
                dp[j]=max(dp[j],dp[j-k[i]]+k[i]);
            }
        }
        printf("%d\n",m-dp[m-5]-k[n-1]);//用m元减m-5元能买的最多的东西，再用剩下的钱-最贵的就是剩的最少的钱
    }
    return 0;
}