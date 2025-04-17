#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<char,int>mp;
    string s,aim="GPLT";
    getline(cin,s);
    mp['G']=mp['P']=mp['L']=mp['T']=0;
    for(char c:s){
        if(aim.find(toupper(c))!=-1){
            mp[toupper(c)]++;
        }
    }
    string out;
    set<pair<int,char>>st;
    for(auto &p:mp) {
        st.insert({p.second,p.first});
    }
    int sum=0;
    while(!st.empty()){
        auto [a,b]=*st.begin();
        
        for(int i=0;i<(a-sum);i++){
            out+=aim;
        }
        sum=a;
        aim.erase(aim.find(b),1);
        st.erase(st.begin());
    }
    cout<<out<<endl;
    return 0;
}