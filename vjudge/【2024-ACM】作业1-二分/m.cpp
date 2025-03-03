#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        mp[t]=i;
    }
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        cout<<mp[x]<<endl;
    }
    return 0;
}