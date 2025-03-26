#include<bits/stdc++.h>
using namespace std;
deque<pair<int,int>>a;
map<int,pair<int,int>>mp;
int main()
{
    
    int firid,n;
    cin>>firid>>n;
    if(n==0) return 0;
    for(int i=0;i<n;i++){
        int fd,v,ld;
        cin>>fd>>v>>ld;
        mp[fd]={v,ld};
    }
    while(firid!=-1){
        auto [v,ld]=mp[firid];
        a.push_back({firid,v});
        firid=ld;
    }
    printf("%05d %d",a.back().first,a.back().second);
    a.pop_back();
    while(!a.empty()){
        if(!a.empty()){
            printf(" %05d\n%05d %d",a.front().first,a.front().first,a.front().second);
            a.pop_front();
        }
        if(!a.empty()){
            printf(" %05d\n%05d %d",a.back().first,a.back().first,a.back().second);
            a.pop_back();
        }
    }
    cout<<" -1";
    return 0;
}