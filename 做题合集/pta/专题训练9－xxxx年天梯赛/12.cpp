#include<bits/stdc++.h>
using namespace std;
int nn=1,xx=1;
unordered_map<int,vector<int>>mmp;
unordered_map<int,int>mp,unor;
void findall(int a){
    stack<int>stk;
    unordered_set<int>vis;
    stk.push(a);
    while(!stk.empty()){
        int now=stk.top();
        stk.pop();
        if(vis.count(now)!=0)continue;
        vis.insert(now);
        for(int next:mmp[now]){
            if(vis.count(next)==0)
                stk.push(next);
        }
    }
    for(auto i:vis){
        unor[i]=xx;
    }
    xx++;
}
int all(){
    int sum=0;
    for(auto&[a,b]:mmp){
        if(unor.count(a)==0){
            findall(a);
            sum++;
        }
    }
    return sum;
}

int main()
{
    int n;
    cin>>n;
    while(n--){
        int t,a;
        cin>>t;
        unordered_set<int>vv;
        while(t--){
            cin>>a;
            mp[a]=nn;
            if(mp.count(a)){
                vv.insert(mp[a]);
            }
        }
        for(auto i:vv){
            mmp[i].push_back(nn);
            mmp[nn].push_back(i);
        }
        nn++;
    }
    cout<<mp.size()<<' '<<all()<<endl;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        if(unor[mp[a]]==unor[mp[b]]){
            cout<<"Y"<<endl;
        }
        else{
            cout<<"N"<<endl;
        }
    }
    return 0;
}