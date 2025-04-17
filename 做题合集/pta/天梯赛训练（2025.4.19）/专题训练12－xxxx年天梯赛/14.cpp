#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>&a,pair<int,int>&b){
    auto[a1,a2]=a;
    auto[b1,b2]=b;
    double da=1.0*a1/a2;
    double db=1.0*b1/b2;
    if(da!=db)return da>db;
    return a2>b2;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>mm(n);
    vector<pair<int,int>>ans(n);
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        mm[i]=t;
    }
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        ans[i]={t,mm[i]};
    }
    sort(ans.begin(),ans.end(),cmp);
    int sum=0;
    int b[m+1]={0};
    for(auto[a1,a2]:ans){
        for(int j=m;j>=a2;j--){
            b[j]=max(b[j],b[j-a2]+a1);
        }
    }
    cout<<b[m];
    return 0;
}