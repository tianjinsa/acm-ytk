#include<bits/stdc++.h>
using namespace std;
unordered_map<string,tuple<string,string,bool>>mp;
unordered_set<string>all;
bool isman(string s){
    if(s[s.size()-1]=='n'||s[s.size()-1]=='m') return 1;
    return 0;
}
string getname(string s){
    if(s[s.size()-1]=='n'){
        s.erase(s.size()-4);
    }
    else if(s[s.size()-1]=='m'){
        s.erase(s.size()-1);
    }
    else if(s[s.size()-1]=='f'){
        s.erase(s.size()-1);
    }
    else{
        s.erase(s.size()-7);
    }
    return s;
}
void dfs(string &s,map<string,int>&vis,int nn){
    if(mp.count(s)==0) return;
    auto &[a,b,c]=mp[s];
    vis[s]=nn;
    dfs(b,vis,nn+1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while(n--){
        string a,b,peo;
        cin>>a>>b;
        bool man=isman(b);
        b=getname(b);
        peo=a+" "+b;
        all.insert(peo);
        mp[a]={peo,b,man};
    }
    cin>>n;
    while(n--){
        string a,b,c,d;
        cin>>a>>b>>c>>d;
        string peo1=a+" "+b;
        string peo2=c+" "+d;
        if(all.count(peo1)==0||all.count(peo2)==0){
            cout<<"NA"<<endl;
            continue;
        }
        auto [x1,y1,z1]=mp[a];
        auto [x2,y2,z2]=mp[c];
        if(z1==z2){
            cout<<"Whatever"<<endl;
            continue;
        }
        map<string,int>vis1,vis2;
        vis1[peo1]=0;
        vis2[peo2]=0;
        dfs(b,vis1,1);
        dfs(d,vis2,1);
        bool fl=1;
        for(auto [s,dd]:vis1){
            if(vis2.count(s)&&(vis2[s]<4||vis1[s]<4)){
                cout<<"No"<<endl;
                fl=0;
                break;
            }
        }
        if(fl){
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}