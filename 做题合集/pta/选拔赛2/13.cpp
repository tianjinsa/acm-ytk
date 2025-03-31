#include<bits/stdc++.h>
using namespace std;
unordered_map<int,unordered_map<int,int>>mp[2];
unordered_map<int,long long>dis[2];
void find(int x){
    bool fl=(x!=1);
    set<pair<int,int>>st;
    st.insert({0,x});
    dis[fl][x]=0;
    while(!st.empty()){
        auto [dd,now]=*st.begin();
        st.erase(st.begin());
        if(dis[fl].count(now)&&dis[fl][now]<dd)continue;
        for(auto [next,l]:mp[fl][now]){
            int ned=dd+l;
            if(!dis[fl].count(next)||dis[fl][next]>ned){
                dis[fl][next]=ned;
                st.insert({ned,next});
            }
        }
    }
}
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    while(m--){
        int u,v,c,d;
        cin>>u>>v>>c>>d;
        if(mp[0][u].count(v)){
            mp[0][u][v]=min(c,mp[0][u][v]);
        }
        else{
            mp[0][u][v]=c;
        }
        if(mp[1][v].count(u)){
            mp[1][v][u]=min(d,mp[1][v][u]);
        }
        else{
            mp[1][v][u]=d;
        }
    }
    find(1);
    find(n);
    vector<int>vva(n);
    for(int i=0;i<n;i++){
        cin>>vva[i];
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        vva[a-1]=b;
        long long minn=LLONG_MAX,sum;
        for(int i=1;i<=n;i++){
            if(!dis[0].count(i)||!dis[1].count(i)) continue;
            sum=dis[0][i]+(dis[1][i]+vva[i-1]-1)/vva[i-1];
            if(sum<minn)minn=sum;
        }
        cout<<minn<<endl;
    }
    return 0;
}