#include<bits/stdc++.h>
using namespace std;
unordered_map<int,pair<char,unordered_set<int>>>mp;
void ss(int x,unordered_set<int>& visit){
    set<pair<int,int>>st;
    map<int,int>dis;
    st.insert({0,x});
    dis[x]=0;
    while(!st.empty()){
        auto t=*(st.begin());
        st.erase(st.begin());
        auto [dd,now]=t;
        if(dd>dis[now]||dd>=4)continue;
        for(auto next:mp[now].second){
            int ned=dd+1;
            if(!dis.count(next)||dis[next]>ned){
                dis[next]=ned;
                visit.insert(next);
                st.insert({ned,next});
            }
        }
    }
}
bool chack(int a,int b){
    unordered_set<int>va,vb;
    ss(a,va);
    ss(b,vb);
    for(auto v:va){
        if(vb.count(v)) return 0;
    }
    return 1;
}
int main()
{
    int n;
    cin>>n;
    while(n--){
        int a,b,c;
        char d;
        cin>>a>>d>>b>>c;
        mp[a].first=d;
        if(b!=-1){
            mp[b].first='M';
            mp[a].second.insert(b);
        }
        if(c!=-1){
            mp[c].first='F';
            mp[a].second.insert(c);
        }
    }
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        if(mp[a].first==mp[b].first){
            cout<<"Never Mind"<<endl;
        }
        else if(chack(a,b)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}