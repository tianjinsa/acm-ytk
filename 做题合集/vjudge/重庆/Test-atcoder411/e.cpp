#include <bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long pow(long long b,long long e,long long mod=MOD)
{
    long long r=1;
    b %= mod;
    while(e>0)
    {
        if(e%2)
            r=r*b%mod;
        b=b*b%mod;
        e/=2;
    }
    return r;
}
long long inv(long long n){
    return pow(n,MOD-2,MOD);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    map<int,vector<int>> m;
    for(int i=1;i <= n;++i)
    {
        for(int j=0;j<6;++j)
        {
            int a;
            cin>>a;
            m[a].push_back(i);
        }
    }
    long long i6=inv(6);
    vector<long long> c(n+1,0);
    long long p=1;
    int z=n;
    long long ans=0;
    long long lv=0;
    for(auto const &[v,dl]:m)
    {
        long long ple=z>0 ? 0:p;
        long long ttt=(1-ple+MOD)%MOD;
        ans=(ans+(v-lv)%MOD*ttt)%MOD;
        map<int,int> u;
        for(int d:dl)
            u[d]++;
        for(auto const &[di,ic]:u)
        {
            long long oc=c[di];
            long long nc=oc+ic;
            if(oc==0)
            {
                z--;
                p=p*nc%MOD*i6%MOD;
            }
            else
            {
                p=p*inv(oc)%MOD*nc%MOD;
            }
            c[di]=nc;
        }
        lv=v;
    }
    cout<<ans<<endl;
    return 0;
}
