#include <bits/stdc++.h>
using namespace std;
map<int,int>mp;
int main() {
    int n,C,t;
    cin>>n>>C;
    for(int i=0;i<n;i++){
        cin>>t;
        ++mp[t];
    }
    long long ans=0;
    for(auto c:mp){
        if(mp.find(c.first+C)!=mp.end())
            ans+=c.second*mp[c.first+C];
    }
    cout<<ans;
    return 0;
}