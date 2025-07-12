#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(n,0));
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        a[u][v]++;
        a[v][u]++;
    }
    long long res=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i][j]>1){
                res=(res+(long long)a[i][j]*(a[i][j]-1)/2);
            }
        }
    }
    long long mod=998244353;
    vector<vector<long long>> dp(1<<n,vector<long long>(n,0));
    for(int i=0;i<n;i++){
        dp[1<<i][i]=1;
    }
    long long t=0;
    for(int mask=1;mask<(1<<n);mask++){
        for(int u=0;u<n;u++){
            if(!(mask&(1<<u)))continue;
            if(!dp[mask][u])continue;
            for(int v=__builtin_ctz(mask);v<n;v++){
                if(!(mask&(1<<v)) && a[u][v]>0){
                    int next_mask=mask|(1<<v);
                    dp[next_mask][v]=(dp[next_mask][v]+dp[mask][u]*a[u][v])%mod;
                }
            }
        }
    }
    for(int mask=1;mask<(1<<n);mask++){
        if(__builtin_popcount(mask)<3)continue;
        int s=__builtin_ctz(mask);
        for(int u=s+1;u<n;u++){
            if(mask&(1<<u)){
                t=(t+dp[mask][u]*a[u][s])%mod;
            }
        }
    }
    long long inv2=(mod+1)/2;
    res=(res+t*inv2)%mod;
    cout<<res<<'\n';
    return 0;
}
