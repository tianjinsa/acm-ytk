#include<bits/stdc++.h>
using namespace std;
map<int,tuple<int,int,int>>stl;
deque<int>in;
map<int,int>mp;
bool ss(int x){
    bool y;
    if(x==0){
        bool f=in.front();
        in.pop_front();
        return f;
    }
    auto& [t,a,b]=stl[x];
    if(t==1){
        y=ss(a)*ss(b);
        return y;
    }
    if(t==2){
        y=ss(a)+ss(b);
        return y;
    }
    y=!ss(a);
    return y;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)mp[i]=i;
    for(int i=1;i<=n;i++){
        int t,a,b;
        cin>>t;
        if(t==3){
            cin>>a;
            mp.erase(a);
            stl[i]={t,a,0};
            continue;
        }
        cin>>a>>b;
        mp.erase(a);
        mp.erase(b);
        stl[i]={t,a,b};
    }
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        for(auto c:s){
            in.push_back(c-'0');
        }
        cout<<(ss(mp.begin()->first)?"Ai":"BuAi")<<endl;
        in.clear();
    }
    
    return 0;
}