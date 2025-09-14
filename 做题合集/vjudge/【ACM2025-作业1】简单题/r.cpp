#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int ms[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int n;
    cin>>n;
    while(n--)
    {
        int m1,d1,c,m2,d2;
        cin>>m1>>d1>>c>>m2>>d2;
        int cd1=0;
        for(int i=1;i<m1;++i)
        {
            cd1+=ms[i];
        }
        cd1+=d1;
        int cd2=0;
        for(int i=1;i<m2;++i)
        {
            cd2+=ms[i];
        }
        cd2+=d2;
        int dd=cd2-cd1;
        long long ans=c*(1LL<<dd);
        cout<<ans<<'\n';
    }
    return 0;
}
