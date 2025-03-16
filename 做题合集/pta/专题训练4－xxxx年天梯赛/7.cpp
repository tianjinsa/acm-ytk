#include<bits/stdc++.h>
using namespace std;
set<int>fri;
set<int>ans;
vector<int>ar;
pair<int,int> findxy(int x,int y){
    auto a=find(ar.begin(),ar.end(),x);
    auto b=find(ar.begin(),ar.end(),y);
    if(a==ar.end()||b==ar.end())return {-1,-1};
    if(a>b)swap(a,b);
    return {a-ar.begin(),b-ar.begin()};
}
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>>tmp(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        tmp[i]={a,b};
    }
    cin>>n;
    ar.resize(n);
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    map<int,int>cut;
    for(auto[x,y]:tmp){
        auto [a,b]=findxy(x,y);
        if(a==-1||b==-1)continue;
        if(a+1==b){
            a-=1;
            b+=2;
        }
        cut[a]+=1;
        cut[b]-=1;
        fri.insert(x);
        fri.insert(y);
    }
    int max=0,nn=0;
    for(int i=0;i<n;i++){
        if(cut.find(i)!=cut.end()){
            nn+=cut[i];
        }
        if(nn>max){
            max=nn;
            ans.clear();
        }
        if(nn==max&&fri.find(ar[i])==fri.end()){
            ans.insert(ar[i]);
        }
    }
    bool fl=0;
    for(auto x:ans){
        if(fl)cout<<" ";
        cout<<x;
        fl=1;
    }
    return 0;
}