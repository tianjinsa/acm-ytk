#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>>mp;
vector<int>an;
struct cmp
{
    bool operator()(tuple<int,int,vector<int>>&a,tuple<int,int,vector<int>>&b){
        auto&[a1,a2,a3]=a;
        auto&[b1,b2,b3]=b;
        if(a1==b1)return a2>b2;
        return a1>b1;
    }
};
tuple<int,int,vector<int>> find(int a,int b){
    unordered_map<int,int>dist;
    priority_queue<tuple<int,int,vector<int>>,vector<tuple<int,int,vector<int>>>,cmp>qq;
    dist[a]=0;
    qq.push({0,an[a],{a}});
    int mind=INT_MAX,maxn=0,ans=0;
    vector<int>out;
    while(!qq.empty()){
        auto[dis,con,road]=qq.top();
        qq.pop();
        int &now=road.back();
        if(dis>dist[now]||dis>mind){
            continue;
        }
        if(now==b){
            mind=dis;
            ans++;
            if(con>maxn){
                maxn=con;
                out=road;
            }
        }
        for(auto&[next,dd]:mp[now]){
            int ned=dis+dd,nec=con+an[next];
            if(!dist.count(next)||ned<=dist[next]){
                vector<int>temp=road;
                temp.push_back(next);
                dist[next]=ned;
                qq.push({ned,nec,temp});
            }
        }
    }
    return {ans,maxn,out};
}
int main()
{
    int n,m,s,d;
    cin>>n>>m>>s>>d;
    mp.resize(n);
    an.resize(n);
    for(int i=0;i<n;i++){
        cin>>an[i];
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        mp[a].push_back({b,c});
        mp[b].push_back({a,c});
    }
    auto[nn,cn,road]=find(s,d);
    cout<<nn<<' '<<cn<<endl;
    bool fl=0;
    for(auto &x:road){
        if(fl)cout<<' ';
        else fl=1;
        cout<<x;
    }
    return 0;
}