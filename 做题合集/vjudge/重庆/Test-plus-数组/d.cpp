#include<bits/stdc++.h>
using namespace std;
vector<unordered_set<int>>mp[2];
int main()
{
    int n,p,q,ans=0;
    cin>>n>>p>>q;
    mp[0].resize(n+1);
    mp[1].resize(n+1);
    for (int i = 0; i < p; i++) {
        int x,y;
        cin >> x >> y;
        mp[0][x].insert(y);
        mp[0][y].insert(x);
    }
    for (int i = 0; i < q; i++) {
        int x,y;
        cin >> x >> y;
        mp[1][x].insert(y);
        mp[1][y].insert(x);
    }
    unordered_set<int> dd;
    for(int w=1;w<=n;w++){
        for(int u: mp[0][w]){
            for(int v: mp[1][w]){
                if(mp[0][u].count(v) || mp[1][u].count(v)) continue;
                auto [a,b]=minmax(u,v);
                dd.insert(a*(n+5) + b);
            }
        }
    }
    cout<<1LL*n*(n-1)/2-q-dd.size()<<endl;
    return 0;
}