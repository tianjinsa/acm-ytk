#include<bits/stdc++.h>
using namespace std;
long long n,m;
bool sea(long long x,vector<long long>& l,vector<long long>& r,vector<long long>& xx,vector<long long>& a){
    vector<long long> b(max(n,m)+2,0),c(max(n,m)+2,0);
    for(long long i=1;i<=x;i++){
        b[l[i]]+=xx[i];
        b[r[i]+1]-=xx[i];
    }
    for(long long i=1;i<=n;i++){
        c[i]+=c[i-1]+b[i];
        if(c[i]>a[i]){
            return 0;
        }
    }
    return 1;
}
int main()
{
    cin>>n>>m;
    vector<long long> x(m+1),l(m+1),r(m+1),a(n+1);
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=m;i++){
        cin>>x[i]>>l[i]>>r[i];
    }
    if(sea(m,l,r,x,a)){
        cout<<0;
        return 0;
    }
    long long le=1,re=m;
    while(le<re){
        long long mid=le+(re-le)/2;
        if(sea(mid,l,r,x,a)){
            le=mid+1;
        }
        else{
            re=mid;
        }
    }
    cout<<-1<<'\n'<<le;
    return 0;
}