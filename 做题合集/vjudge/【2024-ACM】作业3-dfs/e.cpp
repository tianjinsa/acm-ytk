#include<bits/stdc++.h>
using namespace std;
vector<int>a;
int n,m;
void dfs(int d){
    if(d==0){
        for(int i=0;i<n-1;i++){
            cout<<a[i]<<" ";
        }
        cout<<a[n-1]<<endl;
        return;
    }
    for(int i=1;i<=m;i++){
        a.push_back(i);
        dfs(d-1);
        a.pop_back();
    }
}
int main()
{
    cin>>n>>m;
    if(n>0&&m>0)
    dfs(n);
    return 0;
}