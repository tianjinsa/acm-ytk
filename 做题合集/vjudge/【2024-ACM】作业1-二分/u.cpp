#include<bits/stdc++.h>
using namespace std;

int n,m;
long long s;
vector<int>w,v;
vector<pair<int,int>>az;
long long sss(int W){
    vector<long long>a(n+1,0);
    vector<long long>b(n+1,0);
    for(int i=1;i<=n;++i){
        a[i]=a[i-1]+(w[i]>=W?1:0);
        b[i]=b[i-1]+(w[i]>=W?v[i]:0);
    }
    long long all=0;
    for(auto& [l,r]:az){
        all+=(a[r]-a[l-1])*(b[r]-b[l-1]);
    }
    return all;
}
int main(){
    cin>>n>>m>>s;
    w.resize(n+1);
    v.resize(n+1);
    set<int>se;
    int max_w=0;
    for(int i=1;i<=n;++i){
        cin>>w[i]>>v[i];
        se.insert(w[i]);
        if(w[i]>max_w)max_w=w[i];
    }
    az.resize(m);
    for(int i=0;i<m;++i){
        cin>>az[i].first>>az[i].second;
    }
    int l=0,r=se.size()-1;
    long long ans=LLONG_MAX;
    while(l<=r){
        int mid=(l+r)/2;
        long long y=sss(*next(se.begin(),mid));
        if(y<s){
            r=mid-1;
        } else{
            l=mid+1;
        }
        ans=min(ans,abs(y-s));
    }
    cout<<ans<<endl;
    return 0;
}
