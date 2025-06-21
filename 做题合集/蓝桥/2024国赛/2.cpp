#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> a(100005,0);
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >>t;
        a[t]++;
    }
    int ans=0,cut=0,all=n;
    while(n){
        ans++;
        cut=0;
        for(int i = 0; i < 100005; i++)
        {
            while(a[i]&&i> cut)
            {
                cut++;
                a[i]--;
                n--;
            }
            i=cut;
        }
    }
    cout << ans;
    return 0;
}