#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int,int>mp;
    int n,c;
    cin>>n>>c;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        mp[x]++;
    }
    long long sum=0;
    for(auto&[xx,cc]:mp){
        if(!mp.count(c+xx)) continue;
        sum+=1LL*cc*mp[c+xx];
    }
    cout<<sum;
    return 0;
}