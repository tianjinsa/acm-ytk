#include<bits/stdc++.h>
using namespace std;
map<char,map<int,string>>mp;
string s;
vector<int>out;
set<char>vis;
bool dfs(char x,string t=""){
    if(s.find(t)!=0)return 0;
    if(t.size()==s.size()-1){
        return 1;
    }
    for(auto [a,b]:mp[x]){
        if(vis.count(a))continue;
        vis.insert(a);
        out.push_back(a);
        bool fl=dfs(b[b.size()-1],t+b.substr(0,b.size()-1));
        if(!fl){
            out.pop_back();
            vis.erase(a);
        }
        else{
            return 1;
        }
    }
    return 0;
}
int main(){
    int n;
    cin>>n;
    while(n--){
        int t;
        cin>>t;
        t+=10;
        s+=(char)t;
    }
    cin>>n;
    for(int i=1;i<=n;i++){
        int cc;
        cin>>cc;
        string ttt="";
        while(cc--){
            int t;
            cin>>t;
            t+=10;
            ttt+=(char)t;
        }
        mp[ttt[0]][i]=ttt;
    }
    bool fl=0;
    dfs(s[0]);
    for(auto cc:out){
        if(fl)cout<<' ';
        cout<<cc;
        fl=1;
    }
    return 0;
}