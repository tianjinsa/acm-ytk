#include<bits/stdc++.h>
using namespace std;
vector<int> ind;
vector<unordered_set<int>> mp;
int find(int x){
    if(ind[x]==x) return x;
    return ind[x]=find(ind[x]);
}
void unite(int x,int y){
    int rootX=find(x);
    int rootY=find(y);
    if(rootX!=rootY){
        ind[rootX]=rootY;
    }
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    ind.resize(n + 1);
    mp.resize(n + 1);
    iota(ind.begin(), ind.end(), 0);
    while(m--){
        int a,b,x;
        cin>>a>>b>>x;
        if(x==1)unite(a,b);
        else{
            auto[A,B]=minmax(a,b);
            mp[A].insert(B);
        }
    }
    while(k--){
        int a,b;
        cin>>a>>b;
        auto[A,B]=minmax(a,b);
        bool fl1=(find(a)==find(b)),fl2=!(mp[A].count(B));
        if(fl1&&fl2){
            cout<<"No problem"<<endl;
        }
        else if(!fl1&&fl2){
            cout<<"OK"<<endl;
        }
        else if(fl1&&!fl2){
            cout<<"OK but..."<<endl;
        }
        else{
            cout<<"No way"<<endl;
        }
    }
    return 0;
}