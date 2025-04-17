#include<bits/stdc++.h>
using namespace std;
map<int,tuple<set<int>,int,int,double,double>>home;
map<int,int>mp;
int nn=1;
bool cmp(tuple<set<int>,int,int,double,double>&a,tuple<set<int>,int,int,double,double>&b){
    auto& [me1,a1,a2,aa1,bb1]=a;
    auto& [me2,a3,a4,aa2,bb2]=b;
    if(bb1!=bb2){
        return bb1>bb2;
    }
    else{
        return *me1.begin()<*me2.begin();
    }
}
void ss(int& a,vector<int>& member,int N,int S){
    set<int>hh;
    for(auto& i:member){
        if(mp[i]!=0){
            hh.insert(mp[i]);
        }
    }
    if(mp[a]!=0)
        hh.insert(mp[a]);
    if(mp[a]==0||hh.size()!=0){
        if(hh.size()==0&&mp[a]==0){
            mp[a]=nn++;
        }
        else{
            mp[a]=*hh.begin();
            auto& [mb,b,c,d,e]=home[*hh.begin()];
            for(auto ii=next(hh.begin());ii!=hh.end();++ii){
                auto&[mb2,b2,c2,d2,e2]=home[*ii];
                b+=b2;
                c+=c2;
                for(auto& cc:mb2){
                    mp[cc]=mp[a];
                    mb.insert(cc);
                }
                home.erase(*ii);
            }
        }
    }
    auto& [me,a2,a3,aa,bb]=home[mp[a]];
    a2+=N;
    a3+=S;
    me.insert(a);
    for(auto i:member){
        mp[i]=mp[a];
        me.insert(i);
    }
}
int main()
{
    int n;
    cin>>n;
    while(n--){
        int a1,a2,a3,nn;
        cin>>a1>>a2>>a3>>nn;
        vector<int>member;
        if(a2!=-1){
            member.push_back(a2);
        }
        if(a3!=-1){
            member.push_back(a3);
        }
        while(nn--){
            int t;
            cin>>t;
            member.push_back(t);
        }
        int N,S;
        cin>>N>>S;
        ss(a1,member,N,S);
    }
    vector<tuple<set<int>,int,int,double,double>>ans;
    for(auto& i:home){
        auto& [me,a2,a3,aa,bb]=i.second;
        aa=round((double)a2/me.size()*1000.0)/1000.0;
        bb=round((double)a3/me.size()*1000.0)/1000.0;
        ans.push_back(i.second);
    }
    sort(ans.begin(),ans.end(),cmp);
    printf("%d\n",ans.size());
    for(auto& i:ans){
        auto& [me,a2,a3,aa,bb]=i;
        printf("%04d %d %.3lf %.3lf\n",*me.begin(),me.size(),aa,bb);
    }
    return 0;
}