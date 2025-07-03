#include<bits/stdc++.h>
using namespace std;
vector<int> v(100000, 0);
int main()
{
    int n,ans=0;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        v[a[i]]=1;
    }
    sort(a.begin(), a.end());
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(v[a[i]+a[j]]) {
                v[a[i]+a[j]]=0;
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}