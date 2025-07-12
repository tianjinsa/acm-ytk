#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,Q;
    cin>>N>>Q;
    vector<int> a(N+2,0);
    int all=0;
    while(Q--)
    {
        int x;
        cin>>x;
        if(a[x] == 0)
        {
            int l=a[x - 1];
            int r=a[x+1];
            if(!l&&!r)
                all++;
            else if(l&&r)
                all--;
            a[x]=1;
        }
        else
        {
            int l=a[x - 1];
            int r=a[x+1];
            if(!l&&!r)
                all--;
            else if(l&&r)
                all++;
            a[x]=0;
        }
        cout<<all<<'\n';
    }

    return 0;
}