#include<bits/stdc++.h>
using namespace std;
long long n,k,sum=0,ans=0;
vector<int> a;
vector<bool> vis;
bool isp(int x){
    if(x<2)
        return 0;
    if(x==2||x==3)
        return 1;
    if(x%2==0||x%3==0)
        return 0;
    for(int i=5;i*i<=x;i+=6){
        if(x%i==0||x%(i+2)==0)
            return 0;
    }
    return 1;
}
void dfs(int st,int de){
    if(de==k){
        if(isp(sum)){
            ans++;
        }
        return;
    }
    for(int i=st;i<n;i++){
        if(!vis[i]){
            vis[i]=1;
            sum+=a[i];
            dfs(i+1,de+1);
            sum-=a[i];
            vis[i]=0;
        }
    }
}
int main()
{
    
    cin>>n>>k;
    
    a.resize(n);
    vis.resize(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dfs(0,0);
    cout<<ans;
    return 0;
}