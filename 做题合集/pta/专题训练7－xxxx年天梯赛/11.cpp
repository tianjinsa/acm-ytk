#include<bits/stdc++.h>
using namespace std;
int n,m,T;
vector<tuple<int,int,int>>dd;
vector<vector<int>>a;
vector<pair<int,int>> ss(int x,int y){
    
}
int main()
{
    cin>>n>>m>>T;
    a.resize(n+1,vector<int>(m+1));
    for(int i=0;i<=m+1;i++){
        int t;
        cin>>t;
        if(i==0||i==m+1)continue;
        if(t)dd.push_back({0,i,t});
    }
    for(int i=1;i<=n;++i){
        int t;
        cin>>t;
        if(t)dd.push_back({i,0,t});
        for(int j=1;j<=m;++j){
            cin>>a[i][j];
        }
        cin>>t;
        if(t)dd.push_back({i,m+1,t});
    }
    for(int i=0;i<=m+1;i++){
        int t;
        cin>>t;
        if(i==0||i==m+1)continue;
        if(t)dd.push_back({n+1,i,t});
    }
    return 0;
}