#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,k,ans=0,sum=0;
    cin>>n>>k;
    map<int,long long>mp;
    mp[0]=1;
    for(int i=0;i<n;++i){
        long long t;
        cin>>t;
        sum=(sum+t)%k;
        ans+=mp[sum];
        mp[sum]++;
    }
    cout<<ans;
    return 0;
}