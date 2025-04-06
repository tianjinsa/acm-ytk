#include<bits/stdc++.h>
using namespace std;
string me,aim;
struct cmpst{
    bool operator()(const tuple<int,int,int,vector<string>>&a,const tuple<int,int,int,vector<string>>&b)const{
        auto[dd1,ove1,kill1,rd1]=a;
        auto[dd2,ove2,kill2,rd2]=b;
        if(dd1!=dd2)return dd1<dd2;
        if(ove1!=ove2)return ove1>ove2;
        if(kill1!=kill2)return kill1>kill2;
        return rd1<rd2;
    }
};
map<string,int>vo;
map<string,vector<pair<string,int>>>mp;
tuple<int,int,int,vector<string>> ss(){
    map<string,int>dis;
    set<tuple<int,int,int,vector<string>>,cmpst>st;
    dis[me]=0;
    st.insert({0,0,0,{me}});
    bool ffl=1;
    int ans=0;
    tuple<int,int,int,vector<string>>out;
    while(!st.empty()){
        auto[dd,ove,kill,rd]=*st.begin();
        string now=rd.back();
        st.erase(st.begin());
        if(dd>dis[now])continue;
        if(now==aim){
            ans++;
            if(ffl){
                ffl=0;
                out={dd,ove,kill,rd};
            }
        }
        for(auto[next,l]:mp[now]){
            int ned=dd+l;
            vector<string>tt=rd;
            if(!dis.count(next)||ned<=dis[next]){
                tt.push_back(next);
                dis[next]=ned;
                st.insert({ned,ove+1,kill+vo[next],tt});
            }
        }
    }
    auto&[dd,ove,kill,rd]=out;
    ove=ans;
    return out;
}
int main()
{
    int n,k;
    cin>>n>>k>>me>>aim;
    n--;
    while(n--){
        string t;
        int tt;
        cin>>t>>tt;
        vo[t]=tt;
    }
    while(k--){
        string a,b;
        int d;
        cin>>a>>b>>d;
        mp[a].push_back({b,d});
        mp[b].push_back({a,d});
    }
    auto[dd,ove,kill,rd]=ss();
    bool fl=0;
    for(auto city:rd){
        if(fl)cout<<"->";
        else fl=1;
        cout<<city;
    }
    cout<<endl<<ove<<' '<<dd<<' '<<kill;
    return 0;
}