#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll T;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;
        unordered_map<ll,ll>s1,s2;
        bool fl=0,fl2=0;
        vector<ll>a(2,0),b(2,0);
        for(ll i=0;i<n;i++){
            ll t;
            cin>>t;
            a[t%2]++;
            s1[t]++;
            if(!fl){
                if(s1.count(t+1)||s1.count(t-1))fl=1;
            }
        }
        for(ll i=0;i<n;i++){
            ll t;
            cin>>t;
            b[t%2]++;
            s2[t]++;
            if(!fl2){
                if(s2.count(t+1)||s2.count(t-1))fl2=1;
            }
        }
        if(fl&&fl2&&a==b){
            cout<<"Yes\n";
        }
        else if(fl==0&&fl2==0&&s1==s2){
            cout<<"Yes\n";
        }
        else cout<<"No\n";
    }
    return 0;
}