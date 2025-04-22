#include<bits/stdc++.h>
using namespace std;

int main()
{
    int b,n,m,k;
    cin>>b>>n>>m>>k;
    vector<vector<pair<int,pair<int,int>>>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v,c,w;
        cin>>u>>v>>c>>w;
        adj[u].push_back({v,{c,w}});
        adj[v].push_back({u,{c,w}});
    }
    vector<int> queries(k);
    for(int i=0;i<k;i++) cin>>queries[i];
    const int INF = 1e9;
    for(int idx=0;idx<k;idx++){
        int s = queries[idx];
        vector<int> dist(n+1,INF), mood(n+1,-1);
        using T = tuple<int,int,int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        dist[s] = 0; mood[s] = 0;
        pq.emplace(0, 0, s);
        while(!pq.empty()){
            auto [d, neg_m, u] = pq.top(); pq.pop();
            int cur_mood = -neg_m;
            if(d>dist[u] || (d==dist[u] && cur_mood<mood[u])) continue;
            for(auto &e: adj[u]){
                int v = e.first;
                int cost = e.second.first;
                int w = e.second.second;
                int nd = d + cost;
                int nm = cur_mood + w;
                if(nd<dist[v] || (nd==dist[v] && nm>mood[v])){
                    dist[v] = nd;
                    mood[v] = nm;
                    pq.emplace(nd, -nm, v);
                }
            }
        }
        vector<int> reach;
        for(int v=1;v<=n;v++) if(v!=s && dist[v]<=b) reach.push_back(v);
        if(reach.empty()){
            cout<<"T_T"<<"\n";
        } else {
            sort(reach.begin(), reach.end());
            for(size_t i=0;i<reach.size();i++){
                if(i) cout<<" "; cout<<reach[i];
            }
            cout<<"\n";
            int best = 0;
            for(int v:reach) best = max(best, mood[v]);
            vector<int> bests;
            for(int v:reach) if(mood[v]==best) bests.push_back(v);
            sort(bests.begin(), bests.end());
            for(size_t i=0;i<bests.size();i++){
                if(i) cout<<" "; cout<<bests[i];
            }
            cout<<"\n";
        }
    }
    return 0;
}