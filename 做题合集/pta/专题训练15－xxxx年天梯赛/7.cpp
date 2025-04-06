#include<bits/stdc++.h>
using namespace std;
bool isPrime(long long n){
    if(n<=1){
        return 0;
    }
    for(long long i=2;i*i<=n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n,k;
    cin>>n>>k;
    if(n<k){
        cout<<404;
        return 0;
    }
    string s,tt;
    cin>>s;
    tt=s.substr(0,k);
    s.erase(0,k);
    if(isPrime(stoll(tt))){
        cout<<tt;
        return 0;
    }
    for(auto c:s){
        tt.erase(0,1);
        tt+=c;
        if(isPrime(stoll(tt))){
            cout<<tt;
            return 0;
        }
    }
    cout<<404;
    return 0;
}