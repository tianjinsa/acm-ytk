#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    vector<pair<int,string>>v;
    v.push_back({-1,""});
    vector<int>pv(n+1,0);
    int nv=1;
    for(int i=0;i<q;++i){
        int t;
        cin>>t;
        if(t==1){
            int p;
            cin>>p;
            pv[p]=pv[0];
        }else if(t==2){
            int p;
            string s;
            cin>>p>>s;
            v.push_back({pv[p],s});
            pv[p]=nv++;
        }else{
            int p;
            cin>>p;
            pv[0]=pv[p];
        }
    }
    vector<string>res;
    int cv=pv[0];
    while(cv!=-1){
        res.push_back(v[cv].second);
        cv=v[cv].first;
    }
    reverse(res.begin(),res.end());
    for(auto&s:res)cout<<s;
    cout<<'\n';
    return 0;
}
