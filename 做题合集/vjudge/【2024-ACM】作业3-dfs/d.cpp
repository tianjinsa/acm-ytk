#include<bits/stdc++.h>
using namespace std;
vector<int>a;
int n,m;
void dfs(int st,int d){
    if(n-st+1<d)return;
    if(d==0){
        for(int i=0;i<m-1;i++){
            cout<<a[i]<<" ";
        }
        cout<<a[m-1]<<endl;
        return;
    }
    for(int i=st;i<=n;i++){
        a.push_back(i);
        dfs(i+1,d-1);
        a.pop_back();
    }
}
int main()
{
    cin>>n>>m;
    if(m>n||m==0){
        return 0;
    }
    dfs(1,m);
    return 0;
}