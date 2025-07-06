#include<bits/stdc++.h>
using namespace std;

struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const noexcept {
        size_t h1 = hash<T1>{}(p.first);
        size_t h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};
struct UnionFind{
    vector<int> parent;
    vector<bool> top,bottom,left,right;
    UnionFind(int n): parent(n),top(n),bottom(n),left(n),right(n){
        iota(parent.begin(),parent.end(),0);
    }
    int find(int x){
        return parent[x] == x ? x : parent[x]=find(parent[x]);
    }
    void unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a == b) return;
        parent[b]=a;
        top[a]=top[a]||top[b];
        bottom[a]=bottom[a]||bottom[b];
        left[a]=left[a]||left[b];
        right[a]=right[a]||right[b];
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long H,W;
    int K;
    cin>>H>>W>>K;
    vector<pair<int,int>> obs(K);
    unordered_map<pair<int,int>,int,pair_hash> mp;
    for(int i=0;i<K;i++){
        cin>>obs[i].first>>obs[i].second;
        mp[obs[i]]=i;
    }
    if(H == 1&&W == 1){
        cout<<"Yes";
        return 0;
    }
    if(H == 1){
        if(K) cout<<"No";
        else cout<<"Yes";
        return 0;
    }
    if(W == 1){
        if(K) cout<<"No";
        else cout<<"Yes";
        return 0;
    }
    UnionFind uf(K);
    for(int i=0;i<K;i++){
        auto [r,c]=obs[i];
        uf.top[i]=(r == 1);
        uf.bottom[i]=(r == H);
        uf.left[i]=(c == 1);
        uf.right[i]=(c == W);
    }
    int dr[8]={-1,-1,-1,0,0,1,1,1};
    int dc[8]={-1,0,1,-1,1,-1,0,1};
    for(int i=0;i<K;i++){
        auto [r,c]=obs[i];
        for(int d=0;d<8;d++){
            int nr=r + dr[d],nc=c + dc[d];
            auto it=mp.find({nr,nc});
            if(it != mp.end()) uf.unite(i,it->second);
        }
    }
    bool block=false;
    for(int i=0;i<K;i++){
        if(uf.find(i) == i){
            if((uf.top[i]&&uf.bottom[i])||(uf.left[i]&&uf.right[i])||(uf.top[i]&&uf.left[i])||(uf.bottom[i]&&uf.right[i])){
                block=true;
                break;
            }
        }
    }
    cout<<(block?"No":"Yes");
    return 0;
}

