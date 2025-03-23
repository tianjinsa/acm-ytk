#include<bits/stdc++.h>
using namespace std;
map<int,pair<int,int>>lis;
int main()
{
    int n,m,p,sum=0;
    cin>>n>>m>>p;
    while(n--){
        int a,b;
        cin>>a>>b;
        if(a>=175){
            if(b>=p)lis[a].second++;
            else lis[a].first++;
        }
    }
    for(auto [x,p]:lis){
        auto [a,b]=p;
        sum+=min(a,m)+b;
    }
    cout<<sum;
    return 0;
}