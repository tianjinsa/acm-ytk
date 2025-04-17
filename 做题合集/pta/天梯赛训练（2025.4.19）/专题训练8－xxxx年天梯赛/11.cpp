#include<bits/stdc++.h>
using namespace std;

vector<int> far;
set<pair<int,int>> lad;
map<int,int> len;
int N,M,maxx=0;

int ss(int x){
    int tt=x,nn=0;
    while(far[tt]!=-1){
        lad.insert({min(tt,far[tt]),max(tt,far[tt])});
        nn++;
        tt=far[tt];
        if(len.count(tt)){
            nn+=len[tt];
            break;
        }
    }

    maxx=max(maxx,nn);
    len[x]=nn;
    tt=x;
    while(nn--){
        tt=far[tt];
        if(len.count(tt)){
            break;
        }
        len[tt]=nn;
    }
    return lad.size();
}
int main()
{
    cin>>N>>M;
    far.resize(N+1);
    for(int i=1;i<=N;i++){
        cin>>far[i];
    }
    for(int i=0;i<M;i++){
        int x;
        cin>>x;
        cout<<ss(x)*2-maxx<<'\n';
    }
    
    return 0;
}