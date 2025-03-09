#include<bits/stdc++.h>
using namespace std;
pair<long long,long long> ss(pair<long long,long long>& a,pair<long long,long long>& b)
{
    long long x=a.first*b.second+a.second*b.first;
    long long y=a.second*b.second;
    long long z=gcd(x,y);
    return {x/z,y/z};

}
int main()
{
    long long n;
    cin>>n;
    vector<pair<long long,long long>> a(n);
    for(long long i=0;i<n;i++){
        scanf("%lld/%lld",&a[i].first,&a[i].second);
    }
    pair<long long,long long> ans=a[0];
    for(int i=1;i<n;i++){
        ans=ss(ans,a[i]);
    }
    if(ans.second==1){
        cout<<ans.first<<endl;
    }
    else{
        if(ans.first>ans.second){
            cout<<ans.first/ans.second<<" ";
            ans.first%=ans.second;
        }
        if(ans.first!=0){
            cout<<ans.first<<"/"<<ans.second<<endl;
        }
    }
    return 0;
}