#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> mp;
vector<int> dp,vis;
bool fl=1;
int ss(int x){
    vis[x]=1;
    if(dp[x])return dp[x];
    for(int v:mp[x]){
        dp[x]+=ss(v);
    }
    return dp[x];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    
    mp.resize(n+1);
    dp.resize(n+1,0);
    vis.resize(n+1,0);
    while(m--){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
    }
    int x,y;
    cin>>x>>y;
    dp[y]=1;
    cout<<ss(x)<<' ';
    bool fl=1;
    for(int i=1;i<=n;i++){
        if(vis[i]&&!dp[i]){
            fl=0;
            break;
        }
    }
    cout<<(fl?"Yes":"No");
    return 0;
}