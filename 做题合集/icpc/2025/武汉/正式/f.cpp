#include<bits/stdc++.h>
using namespace std;
inline bool cmp(const pair<int,int>&a,const pair<int,int>&b){
    return a.second<b.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;

    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>>qq(m);
        for(auto&[a,b]:qq){
            cin>>a>>b;
        }
        sort(qq.begin(),qq.end(),cmp);

        int ans=0,pos=-1;
        for(const auto&[a,b]:qq){
            if(a<=pos)continue;
            pos=b;
            ans++;
        }
        cout<<(int)ceil(log2(ans+1))<<'\n';
    }
    return 0;
}