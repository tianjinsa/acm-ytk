#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>ss(m);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        while(x--){
            int t;
            cin>>t;
            ss[t-1].push_back(i);
        }
    }
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        set<int>out(ss[a-1].begin(),ss[a-1].end());
        out.insert(ss[b-1].begin(),ss[b-1].end());
        cout<<ss[a-1].size()+ss[b-1].size()-out.size()<<endl;
        
    }
    return 0;
}