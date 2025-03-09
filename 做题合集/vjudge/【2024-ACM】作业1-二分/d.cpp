#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    long long ans=0;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        auto x=upper_bound(a,a+n,t);
        if(x!=a&&x!=a+n)
            ans+=min(abs(t-*x),abs(t-*prev(x)));
        else if(x==a)
            ans+=abs(t-*x);
        else
            ans+=abs(t-*prev(x));
    }
    cout<<ans<<endl;
    return 0;
}