#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,t;
    cin>>n;
    int a[n];
    stack<int>peo;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=n-1;i>=0;i--){
        peo.push(a[i]);
    }
    int m,ans=0;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>t;
        if(!peo.empty()&&peo.top()<=t){
            ans++;
            peo.pop();
        }
    }
    cout<<ans<<endl;
    return 0;
}