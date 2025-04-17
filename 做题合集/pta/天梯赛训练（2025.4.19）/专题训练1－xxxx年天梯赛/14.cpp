#include<bits/stdc++.h>
using namespace std;
map<string,vector<pair<string,int>>>mp;
bool cmp(tuple<string,int,int>&a,tuple<string,int,int>&b){
    auto& [na,ma,sa]=a;
    auto& [nb,mb,sb]=b;
    if(ma!=mb){
        return ma>mb;
    }
    if(sa!=sb){
        return sa<sb;
    }
    int ta=stoi(na.substr(1));
    int tb=stoi(nb.substr(1));
    return ta<tb;
}
int ss(string a,string b){
    set<pair<int,string>> s;
    s.insert({0,a});
    map<string,int>dist;
    dist[a]=0;
    while(!s.empty()){
        auto [d,now]=*s.begin();
        s.erase(s.begin());
        if(d>dist[now])continue;
        if(now==b){
            return d;
        }
        for(auto& [next,len]:mp[now]){
            int ned=d+len;
            if(dist.find(next)==dist.end()||ned<dist[next]){
                dist[next]=ned;
                s.insert({ned,next});
            }
        }
    }
    return -1;
}
int main()
{
    int n,m,k,ds;
    cin>>n>>m>>k>>ds;
    while(k--){
        string a,b;
        int c;
        cin>>a>>b>>c;
        mp[a].push_back({b,c});
        mp[b].push_back({a,c});
    }
    vector<tuple<string,int,int>>ans;
    for(int i=1;i<=m;++i){
        int min=INT_MAX;
        double sum=0;
        string big="G"+to_string(i);
        bool fl=1;
        for(int j=1;j<=n;++j){
            string end=to_string(j);
            int t=ss(big,end);
            if(t==-1||t>ds){
                fl=0;
                break;
            }
            sum+=t;
            min=std::min(t,min);
        }
        if(fl){
            ans.push_back({big,min,round(sum/n*10)});
        }
    }
    if(ans.empty()){
        printf("No Solution");
        return 0;
    }
    sort(ans.begin(),ans.end(),cmp);
    auto&[na,ma,sa]=ans[0];
    printf("%s\n%d.0 %.1lf",na.c_str(),ma,sa/10.0);
    return 0;
}