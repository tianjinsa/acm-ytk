#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    long long mod=998244353;
    vector<vector<long long>> a(n,vector<long long>(n,0));
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;
        a[u][v]++;
        a[v][u]++;
    }
    vector<vector<long long>> dp(1<<n,vector<long long>(n,0));
    for(int i=0;i<n;i++){
        dp[1<<i][i]=1;
    }
    long long ans=0;
    for(int mask=1;mask<(1<<n);++mask){
        int s=__builtin_ctz(mask);
        for(int u=s;u<n;++u){
            if((mask>>u)&1){
                if(dp[mask][u]>0){
                    for(int v=s;v<n;++v){
                        if(a[u][v]>0){
                            if(v==s){
                                if(__builtin_popcount(mask)>=3){
                                    ans=(ans+dp[mask][u]*a[u][v])%mod;
                                }
                            }else{
                                if(!((mask>>v)&1)){
                                    dp[mask|(1<<v)][v]=(dp[mask|(1<<v)][v]+dp[mask][u]*a[u][v])%mod;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    long long inv2=499122177;
    ans=(ans*inv2)%mod;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(a[i][j]>1){
                long long c=a[i][j];
                long long term=c*(c-1)%mod;
                term=term*inv2%mod;
                ans=(ans+term)%mod;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
