#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> a(n+1,0);
    int maxx=0;
    for(int i = 0; i < n; i++)
    {
        int t;

        cin >>t;
        a[t]++;
        maxx = max(maxx, a[t]);
    }
    cout << maxx << endl;
    return 0;
}