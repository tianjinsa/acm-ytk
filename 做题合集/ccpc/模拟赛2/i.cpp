#include<bits/stdc++.h>
using namespace std;
//#define __int128 long long 
const __int128 mod=1e9+7;
const __int128 N=1e7+010;
__int128 qmi(__int128 x,__int128 k,__int128 p)
{
    __int128 res=1;
    while(k)
    {
        if(k&1)
            res=res*x%p;
        k>>=1;
        x=x*x%p;
    }
    return res;
}
__int128 C[N];


__int128 cpls(__int128 n,__int128 k)
{
    
    long long xx=1;
    for(__int128 i=0;i<k;i++)
    {
        xx=(xx*(n-i))%mod;
        xx/=i+1;
        C[i+1]=(xx+mod)%mod;
    }
    return xx%mod;
}
signed main()
{
    long long tn,tR1,tR2,tr,ta,th;
    __int128 n,R1,R2,r,a,h;
    cin>>tn>>tR1>>tR2>>tr>>ta>>th;
    n=tn;
    R1=tR1;
    R2=tR2;
    r=tr;
    a=ta;
    h=th;
    if(n*a<h)
    {
        cout<<0<<endl;
        return 0;
    }
    else if(R1+r>=R2)
    {
        cout<<1<<endl;
        return 0;
    }
    __int128 p=(((R1+r)*(R1+r))%mod)*qmi(R2*R2,mod-2,mod)%mod;
    __int128 fz=(R2*R2-(R1+r)*(R1+r)+mod)%mod;
    __int128 _1p=(fz*qmi(R2*R2,mod-2,mod)+mod)%mod;
    
    __int128 lim=ceil(1.0*h/a);

    cpls(n,n);
    
    __int128 tp=qmi(p,n,mod),_tp=1;
    __int128 modp=qmi(p,mod-2,mod);

    __int128 sum=((tp*_tp)%mod)*C[n]%mod;
    for(__int128 i=n-1;i>=lim;i--)
    {
        tp=(tp*modp)%mod;
        _tp=(_tp*_1p)%mod;
        __int128 tmp=(((tp*_tp)%mod)*C[i])%mod;
        sum=(sum+tmp)%mod;
    }
    long long ans=sum;
    cout<<ans<<endl;
    
}