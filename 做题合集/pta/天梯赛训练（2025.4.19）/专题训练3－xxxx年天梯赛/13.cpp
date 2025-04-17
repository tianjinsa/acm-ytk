#include<bits/stdc++.h>
using namespace std;
unordered_map<int,vector<tuple<int,int,int>>> mp;
tuple<int,int,int,vector<int>> ssml(int a,int b){
    set<tuple<int,int,int,vector<int>>>s;
    s.insert({0,0,a,{a}});
    unordered_map<int,int>dist;
    dist[a]=0;
    while(!s.empty()){
        auto [dd,num,now,all]=*s.begin();
        s.erase(s.begin());
        if(dist.find(now)!=dist.end()&&dd>dist[now])continue;
        if(now==b)return {dd,num,now,all};
        for(auto& [next,len,time]:mp[now]){
            int ned=dd+len;
            if(dist.find(next)==dist.end()||ned<dist[next]){
                dist[next]=ned;
                vector<int>new_all=all;
                new_all.push_back(next);
                s.insert({ned,num+1,next,new_all});
            }
        }
    }
    return {-1,0,0,{}};
}
tuple<int,int,int,vector<int>> ssmt(int a,int b){
    set<tuple<int,int,int,vector<int>>>s;
    s.insert({0,0,a,{a}});
    unordered_map<int,int>dist;
    dist[a]=0;
    while(!s.empty()){
        auto [t,d,now,all]=*s.begin();
        s.erase(s.begin());
        if(dist.find(now)!=dist.end()&&t>dist[now])continue;
        if(now==b)return {t,d,now,all};
        for(auto& [next,len,time]:mp[now]){
            int ned=t+time;
            if(dist.find(next)==dist.end()||ned<dist[next]){
                dist[next]=ned;
                vector<int>new_all=all;
                new_all.push_back(next);
                s.insert({ned,d+len,next,new_all});
            }
        }
    }
    return {-1,0,0,{}};
}
int main()
{
    int n,m;
    cin>>n>>m;
    while(m--){
        int a,b,c,d,t;
        cin>>a>>b>>c>>d>>t;
        if(c){
            mp[a].push_back({b,d,t});
        }
        else{
            mp[a].push_back({b,d,t});
            mp[b].push_back({a,d,t});
        }
    }
    int x,y;
    cin>>x>>y;
    auto [d,num1,num2,alld]=ssml(x,y);
    auto [t,num3,num4,allt]=ssmt(x,y);
    if(alld==allt){
        cout<<"Time = "<<t<<"; Distance = "<<d<<": ";
        for(int i=0;i<alld.size();i++){
            cout<<alld[i];
            if(i<alld.size()-1)cout<<" => ";
        }
        cout<<endl;
    }
    else{
        cout<<"Time = "<<t<<": ";
        for(int i=0;i<allt.size();i++){
            cout<<allt[i];
            if(i<allt.size()-1)cout<<" => ";
        }
        cout<<endl;
        cout<<"Distance = "<<d<<": ";
        for(int i=0;i<alld.size();i++){
            cout<<alld[i];
            if(i<alld.size()-1)cout<<" => ";
        }
        cout<<endl;
    }
    return 0;
}