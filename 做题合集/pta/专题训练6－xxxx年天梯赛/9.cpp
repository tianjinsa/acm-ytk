#include<bits/stdc++.h>
using namespace std;
unordered_set<int>all,visited;
unordered_map<int,vector<int>>mp;
int de(int x){
    int a=visited.size();
    visited.insert(x);
    stack<int>st;
    st.push(x);
    while(!st.empty()){
        int t=st.top();
        st.pop();
        for(auto i:mp[t]){
            if(!visited.count(i)&&all.count(i)){
                visited.insert(i);
                st.push(i);
            }
        }
    }
    //cout<<",,"<<visited.size()-a<<endl;
    return visited.size()-a;
}
int nn(){
    int ans=0;
    for(auto i:all){
        if(!visited.count(i)){
            de(i);
            ans++;
        }
    }
    visited.clear();
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        all.insert(i);
    }
    while(m--){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    cin>>m;
    int a,b;
    a=nn();
    while(m--){
        int x;
        cin>>x;
        int fl=0;
        if(de(x)==1){
            fl=1;
        }
        visited.clear();
        all.erase(x);
        b=nn()+fl;
        if(a==b){
            cout<<"City "<<x<<" is lost."<<endl;
        }
        else{
            cout<<"Red Alert: City "<<x<<" is lost!"<<endl;
        }
        if(all.empty()){
            cout<<"Game Over."<<endl;
            break;
        }
        a=b-fl;
    }
    return 0;
}