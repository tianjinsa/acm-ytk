#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> a(m+1,{0,0});
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        if(a[x].second<y){
            a[x].first=i;
            a[x].second=y;
        }
        else if(a[x].second==y){
            a[x].first=min(a[x].first,i);
        }
    }
    bool fl=0;
    for(int i=1;i<=m;i++){
        if(fl)cout<<' ';
        else fl=1;
        cout<<a[i].first;
    }
    return 0;
}