#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        int n,a,t=0,ans=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            if(a!=t)
                ans++;
            t=a;
        }
        cout<<ans<<endl;
    }
    return 0;
}