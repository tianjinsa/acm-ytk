#include<bits/stdc++.h>
using namespace std;
map<int,vector<pair<int,int>>>mp1;
vector<int>mp2,parent;
map<int,long long>ans;
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void union_sets(int x, int y) {
    int root_x = find(x);
    int root_y = find(y);
    
    if (root_x != root_y) {
        parent[root_x] = root_y;
        mp2[root_y] += mp2[root_x];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        int n,m,q;
        cin>>n>>m>>q;
        mp1.clear();
        mp2.resize(n+1,1);
        parent.resize(n+1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        for(int i=0;i<m;i++){
            int u,v,k;
            cin>>u>>v>>k;
            mp1[k].push_back({u,v});
        }
        for(auto it=prev(mp1.end());;--it) {
            auto[k, v] = *it;
            for(auto [a,b]:v) {
                union_sets(a,b);
            }
            long long anss=0;
            set<int> roots;
            for(int i=0;i<=n;i++){
                roots.insert(find(i));
            }
            for(auto root:roots){
                anss+=(mp2[root]-1)*mp2[root]/2;
            }
            ans[k] = anss;
            if(it==mp1.begin()) {
                break;
            }
        }
        while(q--){
            int tt;
            cin>>tt;
            cout<<ans.lower_bound(tt)->second<<endl;
        }
    }

    return 0;
}