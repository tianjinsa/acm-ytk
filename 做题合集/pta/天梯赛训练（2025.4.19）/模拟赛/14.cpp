#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>a;
vector<int>tree;

void update(int dex,int vv){
    while(dex<tree.size()){
        tree[dex]+=vv;
        dex+=dex&(-dex);
    }
}
int query(int dex){
    int ans=0;
    while(dex>0){
        ans+=tree[dex];
        dex-=dex&(-dex);
    }
    return ans;
}
int query(int l,int r){
    return query(r)-query(l-1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    vector<int>v(n);
    a.resize(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=0;i<n;i++){
        tree.assign(n+1,0);
        update(v[i],1);
        for(int j=i+1;j<n;j++)
        {
            int t=query(v[j],tree.size()-1);
            a[i][j]=a[i][j-1]+t;
            update(v[j],1);
        }
    }

    bool fl=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int tt=(j-i)*(j-i+1)/2;
            if(fl)cout<<' ';
            fl=1;
            cout<<a[0][n-1]-2*a[i][j]+tt;
        }
    }
    return 0;
}
