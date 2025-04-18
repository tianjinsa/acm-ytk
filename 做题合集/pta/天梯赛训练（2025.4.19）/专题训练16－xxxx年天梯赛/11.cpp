#include<bits/stdc++.h>
using namespace std;
unordered_map<int,vector<int>>mp;
int main()
{
    int n;
    cin>>n;
    vector<int>aa(n);
    for(int i=0;i<n;i++)
        aa[i]=i+1;
    set<int>all(aa.begin(),aa.end());
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        int t;
        vector<int>tt;
        while(k--){
            cin>>t;
            tt.push_back(t);
            all.erase(t);
        }
        if(tt.size()>0){
            mp[i]=tt;
        }
    }
    int out=1, maxd=0;
    queue<pair<int,int>> q;
    q.push({*all.begin(),0});
    while(!q.empty()){
        auto [u, d]=q.front();
        q.pop();
        if(mp[u].empty() && d > maxd){
            maxd=d;
            out=u;
        }
        for(int v : mp[u]){
            q.push({v, d + 1});
        }
    }
    cout<<out;
    return 0;
}