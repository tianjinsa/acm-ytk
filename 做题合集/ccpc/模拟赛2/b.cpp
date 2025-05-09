#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct cmp{
    bool operator ()(const pair<ll, int>& a, const pair<ll, int>& b)const
    {
        if(a.second==b.second)
            return a.first>b.first;    
        return a.second<b.second;
    }
};

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int>p(n),d(n);
    for(int i=0;i<n;++i){
        cin>>p[i];
    }
    for(int i=0;i<n;++i){
        cin>>d[i];
    }
    priority_queue<pair<ll, int>>pq;
    pq.push({0,m});
    ll max_profit=0;
    for (int i=0;i<n;++i) 
    {
        set<pair<ll,int>,cmp> temp;
        
        while(!pq.empty()){
            auto current=pq.top();
            pq.pop();
            ll profit=current.first;
            int c=current.second;
            temp.insert({profit,c});
            ll new_profit = profit+(ll)c*p[i];
            int new_c =c/d[i];
            if (new_c>0) {
                temp.insert({new_profit, new_c});
            }
            max_profit=max(max_profit, new_profit);
        }
        int prev_c=-1;
        for (const auto& entry:temp){
            if (entry.second!=prev_c){
                pq.push(entry);
                prev_c=entry.second;
            }
        }
    }
    while(!pq.empty()){
        max_profit=max(max_profit,pq.top().first);
        pq.pop();
    }
    cout<<max_profit<<endl;
    return 0;
}