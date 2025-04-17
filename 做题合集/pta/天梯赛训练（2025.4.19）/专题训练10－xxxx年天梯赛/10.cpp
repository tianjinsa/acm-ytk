#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>>mp;
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        int a;
        cin>>a;
        mp[a].push_back(i);
    }
    deque<pair<int,int>>q;
    q.push_back({1,mp[-1][0]});
    vector<int>out;
    out.push_back(mp[-1][0]);
    int max=1;
    while(!q.empty()){
        auto [nn, t] = q.front();
        q.pop_front();
        for(auto i:mp[t]){
            q.push_back({nn+1,i});
            if(nn+1>max){
                max=nn+1;
                out.clear();
                out.push_back(i);
            }
            else if(nn+1==max){
                out.push_back(i);
            }
        }
    }
    cout<<max<<endl;
    bool fl=0;
    for(auto i:out){
        if(fl)cout<<" ";
        else fl=1;
        cout<<i;
    }
    return 0;
}