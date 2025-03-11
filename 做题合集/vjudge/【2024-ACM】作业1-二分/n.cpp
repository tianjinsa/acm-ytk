#include<bits/stdc++.h>
using namespace std;
map<int,vector<pair<int, int>>>mp;
vector<int>a;
int n,m,b;
bool ss(int max){
    if(a[0]>max)return 0;
    set<pair<int,int>>s;
    map<int,int>dis;
    s.insert({0,0});
    dis[0]=0;
    while(!s.empty()){
        auto [dd,now]=*s.begin();
        s.erase(s.begin());
        if(now==n-1){
            return 1;
        }
        if(dis.find(now)!=dis.end()&&dis[now]<dd)continue;
        for(auto &[next,len]:mp[now]){
            if(a[next]<=max){
                int ned=dd+len;
                if(ned<=b&&(dis.find(next)==dis.end()||ned<dis[next])){
                    dis[next]=ned;
                    s.insert({ned,next});
                }
            }
        }
    }
    return 0;
}
int main()
{
    set<int>st;
    cin>>n>>m>>b;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        st.insert(a[i]);
    }
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        mp[x-1].push_back({y-1,z});
        mp[y-1].push_back({x-1,z});
    }
    if(*prev(st.end())==a[n-1]){
        cout<<a[n-1]<<endl;
        return 0;
    }
    int l=0,r=st.size()-1;
    if(ss(*prev(st.end()))==0){
        cout<<"AFK";
        return 0;
    }
    while(l<r){
        int mid=(l+r)/2;
        if(ss(*next(st.begin(),mid))){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout<<*next(st.begin(),l)<<endl;
    return 0;
}