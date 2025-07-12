#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,m;
    cin>>n>>k>>m;
    vector<int>a(k);
    for(int i=0;i<k;i++) cin>>a[i];
    vector<int>b(m);
    for(int i=0;i<m;i++) cin>>b[i];
    if(k==0){ cout<<0; return 0; }
    vector<int> masks;
    for(int j=0;j<m;j++){
        for(int l=0;l<k;l++){
            int r=l;
            while(r+1<k && a[r+1]-a[l]<=b[j]-1) r++;
            int len=r-l+1;
            if(len>0) masks.push_back(((1<<len)-1)<<l);
        }
    }
    sort(masks.begin(),masks.end());
    masks.erase(unique(masks.begin(),masks.end()),masks.end());
    int full=(1<<k)-1;
    vector<int> dist(1<<k, -1);
    queue<int>q;
    dist[full]=0; q.push(full);
    while(!q.empty()){
        int s=q.front(); q.pop();
        if(s==0) break;
        for(int mask: masks){
            int ns = s ^ mask;
            if(dist[ns]==-1){ dist[ns] = dist[s]+1; q.push(ns); }
        }
    }
    cout<<dist[0];
    return 0;
}