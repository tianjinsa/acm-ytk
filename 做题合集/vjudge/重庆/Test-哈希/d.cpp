#include<bits/stdc++.h>
using namespace std;
string ss(string s) {
    return s.substr(2,2) + s.substr(0,2);
}
int main()
{
    int n;
    cin>>n;
    unordered_map<string,int> mp;
    for(int i=0;i<n;i++){
        string a,b;
        cin>>a>>b;
        a.erase(2);
        mp[a+b]++;
    }
    long long ans=0;
    for(auto &p: mp){
        const string &k=p.first;
        int v=p.second;
        string sk=ss(k);
        if (k < sk && mp.count(sk)) {
            ans += 1LL * v * mp[sk];
        }
    }
    cout<<ans;
    return 0;
}