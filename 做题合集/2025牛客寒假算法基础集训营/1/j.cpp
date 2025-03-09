#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int gcd(int a,int b)
{
    return (b==0)?a:gcd(b,a%b);
}
int main()
{
    int n;
    scanf("%d",&n);
    int tt;
    for(int i=0;i<n;i++){
        scanf("%d",&tt);
        mp[tt]++;
    }
    int ans=0;
    for(auto i=mp.begin();i!=mp.end();++i){
        for(auto j=next(i);j!=mp.end();++j){
            if(gcd(i->first,j->first)==(i->first^j->first)){
                ans+=i->second*j->second;
            }
        }
    }
    printf("%d",ans);
    return 0;
}