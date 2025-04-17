#include<bits/stdc++.h>
using namespace std;
bool chack(string s){
    if(s.size()!=18)return 0;
    for(int i=0;i<17;i++){
        if(s[i]<'0'||s[i]>'9')return 0;
    }
    return 1;
}
map<string,int>mp;
int main()
{
    int d,p;
    cin>>d>>p;
    vector<tuple<string,string>> out1,out2;
    for(int j=0;j<d;j++){
        int t,s;
        cin>>t>>s;
        vector<tuple<string,int,string,string>>list;
        for(int i=0;i<t;i++){
            string a,b,c;
            bool fl;
            cin>>a>>b>>fl>>c;
            if(!chack(b))continue;
            if(fl){
                out2.push_back({a,b});
            }
            list.push_back({c,i,a,b});
        }
        sort(list.begin(),list.end());
        int add=0;
        for(int i=0;i<s+add&&i<list.size();i++){
            auto[t,x,n,nn]=list[i];
            if(mp.count(nn)&&j-mp[nn]<=p){
                add++;
                continue;
            }
            mp[nn]=j;
            out1.push_back({n,nn});
        }
    }
    for(auto& [name, number]:out1){
        cout<<name<<" "<<number<<endl;
    }
    set<string>vis;
    for(auto[a,b]:out2){
        if(vis.count(b)==0){
            vis.insert(b);
            cout<<a<<" "<<b<<endl;
        }
    }
    return 0;
}