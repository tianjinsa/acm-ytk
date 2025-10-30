#include<bits/stdc++.h>
using namespace std;
struct node
{
    int fa;
    vector<int>chd;
    node(){
        fa=-1;
    }
};
vector<long long>vv,v2;
vector<node>aa;
vector<int>cen;
vector<vector<int>>up;
long long get_hash(int x,int y){
    return ((long long)x<<32)|y;
}
bool cmp(const int &a,const int &b)
{
    return v2[a]<v2[b];
}
int dfs(int u){
    if(v2[u]) return v2[u];
    if(aa[u].chd.empty()){
        return v2[u]=vv[u];
    }
    vector<long long>tmp;
    for(auto &it:aa[u].chd){
        tmp.push_back(dfs(it));
    }
    sort(tmp.begin(),tmp.end());
    return v2[u]=min(vv[u],tmp[0]+tmp[1]);
}
int lca(int x,int y)
{
    if(cen[x]<cen[y])swap(x,y);
    for(int i=21;i>=0;i--){
        if(up[i][x]!=-1&&cen[up[i][x]]>=cen[y]){
            x=up[i][x];
        }
    }
    if(x==y)return x;
    for(int i=21;i>=0;i--){
        if(up[i][x]!=-1&&up[i][x]!=up[i][y]){
            x=up[i][x];
            y=up[i][y];
        }
    }
    return up[0][x];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        vv.assign(n,0);
        v2.assign(n,0);
        vector<vector<int>>mp(n);
        up.assign(22,vector<int>(n,-1));
        aa.assign(n, node());
        cen.assign(n,0);
        vector<long long>ans(n, 0);
        for(int i=0;i<n;i++){
            cin>>vv[i];
        }
        for(int i=0;i<n-1;i++){
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            mp[x].push_back(y);
            mp[y].push_back(x);
        }

        stack<pair<int,long long>>s;
        s.push({0,0});
        while(!s.empty()){
            auto [u,cenx]=s.top();
            s.pop();
            up[0][u]=aa[u].fa;
            for(int i=1;i<22;i++){
                if(up[i-1][u]!=-1){
                    up[i][u]=up[i-1][up[i-1][u]];
                }
            }
            for(int v:mp[u]){
                if(v==aa[u].fa)continue;
                aa[v].fa=u;
                aa[u].chd.push_back(v);
                s.push({v,cenx+1});
                cen[v]=cenx+1;
            }
        }
        
        

        dfs(0);
        for(auto &it:aa){
            sort(it.chd.begin(),it.chd.end(),cmp);
        }
        s.push({0,0});
        while(!s.empty()){
            auto [u,cont]=s.top();
            s.pop();
            ans[u]=cont;
            for(int &v:aa[u].chd){
                long long tsum=cont;
                if(aa[u].chd[0]!=v){
                    tsum+=v2[aa[u].chd[0]];
                }
                else{
                    tsum+=v2[aa[u].chd[1]];
                }
                s.push({v,tsum});
            }
        }

        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            int anc=lca(x,y);
            long long sum=0;
            if(anc!=y)sum=-1;
            else{
                sum=ans[x]-ans[y];
            }
            cout<<sum<<'\n';
        }
    }
    return 0;
}
