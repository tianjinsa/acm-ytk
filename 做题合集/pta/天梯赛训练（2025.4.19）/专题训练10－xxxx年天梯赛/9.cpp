#include<bits/stdc++.h>
using namespace std;
int n,m;
map<int,vector<int>>mp;
set<int>st1,st2;
bool ss(){
    for(auto i:st2){
        for(auto a:mp[i]){
            if(st2.find(a)!=st2.end()){
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        st1.insert(i);
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    cin>>m;
    while(m--){
        int t;
        cin>>t;
        st2=st1;
        for(int i=0;i<t;i++){
            int a;
            cin>>a;
            st2.erase(a);
        }
        if(ss()){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}