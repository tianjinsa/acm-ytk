#include<bits/stdc++.h>
using namespace std;
bool cmp1(pair<int,string> a,pair<int,string> b){
    if(a.first!=b.first)return a.first<b.first;
    return a.second>b.second;
}
bool cmp2(pair<int,string> a,pair<int,string> b){
    if(a.first!=b.first)return a.first<b.first;
    return a.second<b.second;
}
int main()
{
    int n,g,k;
    cin>>n>>g>>k;
    vector<pair<int,string>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].second>>a[i].first;
    }
    sort(a.begin(),a.end(),cmp1);
    int ia=(lower_bound(a.begin(),a.end(),make_pair(60,""),cmp2)-a.begin());
    int ib=(lower_bound(a.begin(),a.end(),make_pair(g,""),cmp2)-a.begin());
    int sum=0;
    for(int i=ia;i<ib;i++){
        sum+=20;
    }
    for(int i=ib;i<n;i++){
        sum+=50;
    }
    cout<<sum<<endl;
    vector<tuple<int,string,int>> out;
    ia=2;
    out.push_back({1,a[n-1].second,a[n-1].first});
    for(int i=n-2;i>=0;i--){
        auto [t1,t2]=a[i];
        auto [x1,x2,x3]=out.back();
        if(t1<x3){
            if(out.size()>=k)break;
            out.push_back({ia,t2,t1});
        }
        else{
            
            out.push_back({x1,t2,t1});
        }
        ia++;
    }
    for(auto [a1,a2,a3]:out)
        cout<<a1<<" "<<a2<<" "<<a3<<endl;
    return 0;
}