#include<bits/stdc++.h>
using namespace std;

long long n;
vector<vector<pair<long long,long long>>> graph;
vector<char> gender;
vector<vector<long long>> dis;

void ss(){
    for(long long i=1;i<=n;i++){
        dis[i][i]=0;
    }
    for(long long i=1;i<=n;i++){
        for(auto &p:graph[i]){
            long long j=p.first;
            long long d=p.second;
            dis[i][j]=min(dis[i][j],d);
        }
    }
    for(long long k=1;k<=n;k++){
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=n;j++){
                if(dis[i][k]<LLONG_MAX&&dis[k][j]<LLONG_MAX){
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
    }
}

int main(){
    cin>>n;
    
    graph.resize(n+1);
    gender.resize(n+1);
    dis.resize(n+1,vector<long long>(n+1,LLONG_MAX));

    for(long long i=1;i<=n;i++){
        cin>>gender[i];
        long long k;
        cin>>k;
        for(long long j=0;j<k;j++){
            long long fid,ds;
            char cc;
            cin>>fid>>cc>>ds;
            graph[i].push_back({fid,ds});
        }
    }
    ss();
    
    vector<long long> fout,mout;
    long long fmax=LLONG_MAX,mmax=LLONG_MAX;
    
    for(long long i=1;i<=n;i++){
        long long len=0;
        for(long long j=1;j<=n;j++){
            if((gender[i]=='F'&&gender[j]=='M')||(gender[i]=='M'&&gender[j]=='F')){
                len=max(len,dis[j][i]);
            }
        }
        long long pop=len;
        if(gender[i]=='F'){
            if(pop<fmax){
                fmax=pop;
                fout.clear();
                fout.push_back(i);
            }
            else if(pop==fmax){
                fout.push_back(i);
            }
        }
        else{
            if(pop<mmax){
                mmax=pop;
                mout.clear();
                mout.push_back(i);
            }
            else if(pop==mmax){
                mout.push_back(i);
            }
        }
    }
    for(long long i=0;i<fout.size();i++){
        if(i>0)cout<<" ";
        cout<<fout[i];
    }

    cout<<endl;
    for(long long i=0;i<mout.size();i++){
        if(i>0)cout<<" ";
        cout<<mout[i];
    }
    cout<<endl;
    
    return 0;
}