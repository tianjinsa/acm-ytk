#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,l,r,t;
    cin>>n>>l>>r;
    vector<int> a(n+1,0);
    
    for(int i = 1; i <= n; i++) {
        cin >> t;
        a[i] = t+a[i-1];
    }
    double ans=0;
    for(int i=l;i<=r;i++){
        int sum=0;
        for(int j=0;j<=n-i;j++){
            sum=max(sum,a[j+i]-a[j]);
        }
        ans=max(ans,1.0*sum/i);
    }
    printf("%.3lf\n",ans);
    
    return 0;
}