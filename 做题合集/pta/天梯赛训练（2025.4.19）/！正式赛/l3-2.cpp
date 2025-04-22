#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll Sfunc(ll x,ll y){ ll L=min(x,y); return x*y*L - (x+y)*(L*(L-1)/2) + ((L-1)*L*(2*L-1)/6); }
int main(){ ios::sync_with_stdio(false); cin.tie(NULL);
    int n,m; if(!(cin>>n>>m)) return 0;
    vector<vector<ll>> s(n+1, vector<ll>(m+1));
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>s[i][j];
    vector<ll> A(n+1), B(m+1);
    for(int i=1;i<=n;i++){ ll a=i-1,b=n-i; A[i] = a*(a+1)/2 + b*(b+1)/2; }
    for(int j=1;j<=m;j++){ ll c=j-1,d=m-j; B[j] = c*(c+1)/2 + d*(d+1)/2; }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ll a=i-1,b=n-i,c=j-1,d=m-j;
            ll sum_min = Sfunc(a,c) + Sfunc(a,d) + Sfunc(b,c) + Sfunc(b,d);
            ll xpmclzjkln = A[i]*m + B[j]*n - sum_min;
            ll ans = s[i][j] * xpmclzjkln;
            cout<<ans<<(j<m?' ':'\n');
        }
    }
    return 0;
}