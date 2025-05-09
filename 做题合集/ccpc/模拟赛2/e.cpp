#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,k;
    
    cin>>n>>k;
    map<long long,pair<vector<long long>,int>>mp;
    while(n--){
        long long a,b,v;
        cin>>a>>b>>v;
        mp[a].first.push_back(v);
        mp[b+1].first.push_back(v);
        mp[a].second++;
        mp[b+1].second--;
    }
    bool fl=0;
    long long maxx=0,ans=0,ansn=0;
    for (const auto& entry : mp) {
        ansn+=entry.second.second;  
        for(auto v:entry.second.first){
            ans^=v;
        }
        if(ansn>=k){
            fl=1;
            maxx=max(maxx,ans);
        }
    }
    if(!fl){
        cout<<-1<<endl;
        return 0;
    }
    cout << maxx << endl;

    return 0;
}