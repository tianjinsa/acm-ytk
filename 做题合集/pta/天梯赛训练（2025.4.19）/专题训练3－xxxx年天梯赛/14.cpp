#include<bits/stdc++.h>
using namespace std;
unordered_map<int,vector<int>>mp;
unordered_set<int>st;
bool ff(int b){
    for(auto& i:mp[b]){
        if(st.find(i)==st.end()){
            return 0;
        }
    }
    return 1;
}
int ss(int a){
    int max=0,minxx=a;
    set<pair<int,int>> s;
    s.insert({0,a});
    st.insert(a);
    unordered_map<int,int>dist;
    dist[a]=0;
    while(!s.empty()){
        auto [d,now]=*s.begin();
        s.erase(s.begin());
        if(dist.find(now)!=dist.end()&&d>dist[now])continue;
        if(ff(now)){
            if(d>max){
                max=d;
                minxx=now;
            }
            else if(d==max&&now<minxx){
                minxx=now;
            }
            continue;
        }
        for(auto& next:mp[now]){
            int ned=d+1;
            if(dist.find(next)==dist.end()||ned<dist[next]){
                dist[next]=ned;
                s.insert({ned,next});
                st.insert(next);
            }
        }
    }
    st.clear();
    return minxx;
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    while(m--){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    while(k--){
        int a;
        cin>>a;
        if(mp.find(a)==mp.end()){
            cout<<0<<endl;
            continue;
        }
        else{
            cout<<ss(a)<<endl;
        }
    }
    return 0;
}