#include<bits/stdc++.h>
using namespace std;
long long mod=998244352;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long n;
    cin>>n;
    vector<vector<long long>> a(n,vector<long long>(n,1));
    for(long long i=0;i<n;++i){
        cin>>a[i][i];
        a[i][i]=(a[i][i]+1)%mod;
        for(long long j=0;j<i;++j){
            a[i][j]=(a[i][i]-1)%mod;
            a[j][i]=(a[j][j]-1)%mod;
        }
    }
    for(long long i=0;i<n;++i){
        for(long long j=0;j<n;++j){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}