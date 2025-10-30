#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin>>n;
    long long r=(long long)sqrt(n);
    long long c=n/r;
    long long rem=n%r;
    long long ans=2*n+r+c;
    if(rem){
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
