#include<bits/stdc++.h>
using namespace std;
map<long long,map<long long,long long>>mp;
int main()
{
    long long n,m;
    cin>>n>>m;
    while(m--){
        long long a,b,c;
        cin>>a>>b>>c;
        mp[a][b]=c;
        mp[b][a]=c;
    }
    set<long long>st,tt;
    for(long long i=1;i<=n;i++){
        st.insert(i);
    }
    cin>>m;
    long long out=0,out2=0;
    long long minn=INT_MAX;
    for(long long i=1;i<=m;i++){
        tt=st;
        long long t,dd=0;
        cin>>t;
        if(t!=n){
            int x;
            while(t--)cin>>x;
            continue;
        }
        long long tx=0;
        bool fl=1;
        while(t--){
            long long x;
            cin>>x;
            if(!mp[tx].count(x)||!fl){
                fl=0;
                continue;
            }
            dd+=mp[tx][x];
            tx=x;
            tt.erase(x);
        }
        if(!mp[tx].count(0)||!fl){
            continue;
        }
        dd+=mp[tx][0];
        if(tt.size()==0&&fl){
            out2++;
            if(dd<minn){
                minn=dd;
                out=i;
            }
        }
    }
    cout<<out2<<endl;
    cout<<out<<' '<<minn<<endl;
    return 0;
}