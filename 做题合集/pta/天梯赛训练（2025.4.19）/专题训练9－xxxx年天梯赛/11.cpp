#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>>mp;
vector<int>cl;
bool find(){
    for(int i=1;i<=mp.size();i++){
        for(auto& a:mp[i]){
            if(cl[i]==cl[a])return 0;
        }
    }
    return 1;
}
int main()
{
    int n,m,k;
    
    cin>>n>>m>>k;
    cl.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    cin>>m;
    while(m--){
        set<int>st;
        for(int i=1;i<=n;i++){
            cin>>cl[i];
            st.insert(cl[i]);
        }
        if(st.size()!=k||!find())cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}