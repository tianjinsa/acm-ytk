#include<bits/stdc++.h>
using namespace std;

long long gcd(long long x, long long y) {
    return y ? gcd(y, x % y) : x;
}
long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if(!b){x=1; y=0; return a;}
    long long d=extended_gcd(b, a%b, y, x);
    y-= (a/b)*x;
    return d;
}
int main()
{
    while(true) {
        int n; cin >> n; 
        if(!cin || n==0) break;
        vector<long long> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        bool ok=true;
        for(int i=0;i<n && ok;i++){
            for(int j=i+1;j<n && ok;j++){
                if(gcd(a[i], a[j])!=1) ok=false;
            }
        }
        if(!ok){cout<<"NO\n";continue;}
        long long A=1; 
        for(int i=0;i<n;i++) A*=a[i];
        vector<long long> b(n);
        for(int i=0;i<n;i++){
            long long Ai=A/a[i], x,y;
            extended_gcd(Ai, a[i], x, y);
            x=(x%a[i]+a[i])%a[i];
            b[i]=(Ai%A * x)%A;
        }
        for(int i=0;i<n;i++){
            cout<<b[i]; 
            if(i<n-1) cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}