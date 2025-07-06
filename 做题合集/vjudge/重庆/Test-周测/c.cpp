#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        vector<int>v(x);
        set<int> s;
        for(int i=0;i<x;i++){
            cin>>v[i];
            if(i>0 && i<x-1){
                s.insert(v[i]);
            }
        }
        
        int ans=2,t=v[0],tt=t;
        while(t*2<v[x-1]){
            auto it = s.upper_bound(t*2);
            if(it == s.begin()) break;
            t = *prev(it);
            if(t<=tt) {
                ans = -1;
                break;
            }
            ans++;
            tt=t;
        }
        if(v[x-1]>t*2)ans=-1;
        cout<<ans<<'\n';
    }
    return 0;
}