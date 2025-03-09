#include<bits/stdc++.h>
using namespace std;
long long sss(vector<long long> a,long long x)
{
    long long nn=0;
    for(long long i=0;i<a.size();i++)
    {
        if(a[i]>=x)
        {
            nn++;
        }
    }
    return nn;
}
int main()
{
    long long n,m;
    cin>>n>>m;
    vector<long long> a(m);
    for(long long i=0;i<m;i++)
    {
        cin>>a[i];
    }
    long long max=0,maxx;
    
    for(long long i=0; i<m; i++)
    {
        long long t=min(sss(a,a[i]),n)*a[i];
        if(t>max)
        {
            max=t;
            maxx=a[i];
        }
    }
    
    cout<<maxx<<' '<<max;

    return 0;
}