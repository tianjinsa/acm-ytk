#include<bits/stdc++.h>
using namespace std;
vector<int> ind(10000);
map<int,tuple<int,int,int>>mp;
int find(int x){
    if(ind[x]==x) return x;
    return ind[x]=find(ind[x]);
}
void unite(int x,int y){
    int rootX=find(x);
    int rootY=find(y);
    if(rootX!=rootY){
        auto[Y,X]=minmax(rootX,rootY);
        ind[X]=Y;
        auto& [x1, x2, x3] = mp[X];
        auto& [y1, y2, y3] = mp[Y];
        if(x1==0)x1=1;
        if(y1==0)y1=1;
        y1+=x1;
        y2+=x2;
        y3+=x3;
        mp.erase(X);
    }
}

bool cmp(const tuple<int,int,double,double>&a,const tuple<int,int,double,double>&b){
    auto&[x1,y1,z1,w1]=a;
    auto&[x2,y2,z2,w2]=b;
    if(w1==w2)return x1<x2;
    return w1>w2;
}
int main()
{
    iota(ind.begin(), ind.end(), 0);
    int n;
    cin>>n;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        vector<int>v;
        if(b!=-1)v.push_back(b);
        if(c!=-1)v.push_back(c);
        int k;
        cin>>k;
        while(k--){
            int x;
            cin>>x;
            v.push_back(x);
        }
        for(int i:v){
            unite(a,i);
        }
        int d,e;
        cin>>d>>e;
        auto&[x1,x2,x3]=mp[find(a)];
        if(x1==0)x1=1;
        x2+=d;
        x3+=e;
    }
    vector<tuple<int,int,double,double>>res;
    for(auto& [k,v]:mp){
        auto& [x1, x2, x3] = v;
        res.push_back({k,x1,round((double)x2/x1*1000)/1000.0,round((double)x3/x1*1000)/1000.0});
    }
    sort(res.begin(),res.end(),cmp);
    cout<<res.size()<<endl;
    for(auto& [k,x1,x2,x3]:res){
        printf("%04d %d %.3f %.3f\n",k,x1,x2,x3);
    }
    return 0;
}