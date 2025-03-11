#include<bits/stdc++.h>
using namespace std;
unordered_map<int,pair<unordered_set<int>,unordered_set<int>>>mp;
unordered_map<int,vector<int>>mp2;
bool ss(int a,int b){
    set<pair<int,int>> s;
    s.insert({0,a});
    map<int,int>dist;
    dist[a]=0;
    while(!s.empty()){
        auto [d,now]=*s.begin();
        s.erase(s.begin());
        if(d>dist[now])continue;
        if(now==b){
            return 1;
        }
        for(auto& next:mp2[now]){
            int ned=d+1;
            if(dist.find(next)==dist.end()||ned<dist[next]){
                dist[next]=ned;
                s.insert({ned,next});
            }
        }
    }
    return 0;
}
int main()
{
    int m,k;
    cin>>m>>m>>k;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        if(c==1){
            mp[a].first.insert(b);
            mp[b].first.insert(a);
            mp2[a].push_back(b);
            mp2[b].push_back(a);
        }
        else{
            mp[a].second.insert(b);
            mp[b].second.insert(a);
        }
    }
    while(k--){
        int a,b;
        cin>>a>>b;
        if(mp[a].first.find(b)!=mp[a].first.end()){
            cout<<"No problem"<<endl;
        }
        else if(mp[a].first.find(b)==mp[a].first.end()&&mp[a].second.find(b)==mp[a].second.end()){
            cout<<"OK"<<endl;
        }
        else{
            if(ss(a,b)){
                cout<<"OK but..."<<endl;
            }
            else{
                cout<<"No way"<<endl;
            }
        }
    }
    return 0;
}