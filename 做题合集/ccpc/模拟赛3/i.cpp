#include<bits/stdc++.h>
using namespace std;

long long qmi(long long a,long long e,long long mod){
    long long res=1%mod;
    a %= mod;
    while(e){
        if(e & 1) res=(res*a)%mod;
        a=(a*a)%mod;
        e >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k,m,q;
    cin>>n>>k>>m>>q;
    vector<char> flg(n,0);
    for(int i=0;i<m;i++){
        long long x;
        cin>>x;
        for(int j=1;j<=k;j++){
            flg[qmi(x,j,n)]=1;
        }
    }
    bool fl=0;
    for(int i=0;i<q;i++){
        long long y;
        cin>>y;
        bool ok=1;
        for(int j=1;j<=k;j++){
            int xx=qmi(y,j,n);
            if(!flg[xx]){
                ok=0;
                break;
            }
        }
        if(fl)cout<<' ';
        else fl=1;
        cout<<ok;
    }
    return 0;
}