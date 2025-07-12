#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<long long> r;
vector<int> d,s,t;

auto check(int k)
{
    vector<long long> b(n+2,0);
    for(int i=1;i<=k;++i)
    {
        b[s[i]]+=d[i];
        b[t[i]+1]-=d[i];
    }
    long long need=0;
    for(int i=1;i<=n;++i)
    {
        need+=b[i];
        if(need>r[i])
        {
            return 0;
        }
    }
    return 1;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;

    r.resize(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>r[i];
    }

    d.resize(m+1);
    s.resize(m+1);
    t.resize(m+1);
    for(int i=1;i<=m;++i)
    {
        cin>>d[i]>>s[i]>>t[i];
    }

    int l=1,R=m,ans=0;
    while(l<=R)
    {
        int mid=l+(R-l)/2;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            R=mid-1;
        }
    }

    if(ans==m)
    {
        cout<<0<<endl;
    }
    else
    {
        cout<<-1<<endl;
        cout<<ans+1<<endl;
    }

    return 0;
}
