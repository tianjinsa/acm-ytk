#include<bits/stdc++.h>
using namespace std;
bool cmp(tuple<int,int,int> &a,tuple<int,int,int> &b) {
    auto [a1,a2,a3]=a;
    auto [b1,b2,b3]=b;
    if(a2!=b2){
        return a2>b2;
    }
    if(a3!=b3){
        return a3>b3;
    }
    return a1<b1;
}

int main()
{
    map<int,pair<int,int>>mp;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int t,sum=0;
        cin>>t;
        while(t--){
            int k,p;
            cin>>k>>p;
            mp[k].first+=p;
            mp[k].second++;
            sum+=p;
        }
        mp[i].first-=sum;
    }
    vector<tuple<int,int,int>> v;
    for (auto &[id,p]:mp) {
        v.emplace_back(id,p.first,p.second);
    }
    sort(v.begin(),v.end(),cmp);
    for(auto &[a1,a2,a3]:v){
        printf("%d %.2lf\n",a1,a2/100.0);
    }
    return 0;
}