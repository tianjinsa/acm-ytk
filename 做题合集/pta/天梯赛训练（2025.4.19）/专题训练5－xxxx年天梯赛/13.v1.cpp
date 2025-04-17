#include<bits/stdc++.h>
using namespace std;
int ae,ad;
vector<pair<int,int>>va;
unordered_map<int,vector<int>>city;
unordered_map<int,vector<pair<int,int>>>mp;

pair<int,int> ss(int x,int y){
    unordered_map<int,int>dis;
    set<tuple<int,int,int>>pq;
    dis[x]=0;
    pq.insert({0,0,x});
    while(!pq.empty()){
        auto [d,nd,now]=*pq.begin();
        pq.erase(pq.begin());
        if(dis[now]<d)continue;
        if(now==y)return {d,nd};
        for(auto [next,len]:mp[now]){
            int ned=d+len;
            if(dis.find(next)==dis.end()||ned<dis[next]){
                dis[next]=ned;
                pq.insert({ned,nd+1,next});
            }
        }
    }
    return {-1,-1};
}

tuple<int,int,int> next_aim(){
    int max=0;
    unordered_set<int>aim;
    for(auto [x,y]:va){
        if(max<x&&x<=ae){
            aim.clear();
            max=x;
            aim.insert(y);
        }
        else if(max==x)aim.insert(y);
    }
    if(aim.empty())
        return {0,0,-1};
    vector<tuple<int,int,int>>ans;
    for(auto y:aim){
        auto [d,nd]=ss(ad,y);
        if(d!=-1)ans.push_back({d,nd,y});
    }
    auto [a,b,c]=*min_element(ans.begin(),ans.end());
    return {max,c,a};
}

int main()
{
    int n,m,d;
    cin>>n>>m>>m>>d;
    cin>>ae>>ad;
    while(n--){
        int x,y;
        cin>>x>>y;
        va.push_back({x,y});
        city[y].push_back(x);
    }
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        mp[a].push_back({b,c});
        mp[b].push_back({a,c});
    }
    while(d){
        auto [aime,aimy,ld]=next_aim();
        if(ld==-1)break;
        d-=ld;
        if(d<=0)break;
        ad=aimy;
        d--;
        if(d<=0)break;
        ae+=aime;
        int sum=0;
        bool fl=0;
        for(auto e:city[ad]){
            if(e<=ae){
                sum+=e;
                va.erase(find(va.begin(),va.end(),make_pair(e,ad)));
                city[ad].erase(find(city[ad].begin(),city[ad].end(),e));
            }
            else fl=1;
        }
        if(sum>ae)fl=1;
        if(fl){
            va.push_back({sum,ad});
            city[ad].push_back(sum);
        }
        else{
            d--;
            if(d<=0)break;
            ae+=sum;
        }
        d--;
    }
    return 0;
}