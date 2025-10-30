#include<bits/stdc++.h>
using namespace std;


int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int n;
    cin>>n;
    vector<long long> time(n);
    vector<int> pos(n);
    vector<int> aim(n);
    vector<bool> dir(n);
    for(int i=0;i<n;i++){
        cin>>aim[i];
        aim[i]--;
    }
    for(int i=0;i<n;i++){
        cin>>pos[i];
        pos[i]*=2;
    }
    for(int i=0;i<n;i++){
        dir[i]=(pos[aim[i]]<pos[i]);//1表示向左
    }
    long long dd=0;
    vector<bool> stop(n, 0);
    int vt=n;
    // priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    while(vt){
        long long min_time=LLONG_MAX;
        int min_index=-1;
        for(int i=0;i<n;i++){
            if(!stop[i]){
                int &v=aim[i];
                long long dist=abs(pos[v]-pos[i]);
                long long rel_v=0;
                if(dir[i]==dir[v]&&!stop[v]){
                    continue;
                }else if(stop[v]){
                    rel_v=1;
                }else{
                    rel_v=2;
                }
                if(rel_v!=0){
                    if(abs(dist/rel_v)<min_time){
                        min_time=abs(dist/rel_v);
                        min_index=i;
                    }
                }
            }
        }
        long long dt=min_time;
        for(int i=0;i<n;i++){
            if(!stop[i]){
                pos[i]+=(dir[i]? -dt:dt);
            }
        }
        dd+=min_time;
        time[min_index]=dd;
        stop[min_index]=1;
        vt--;
    }
    for(int i=0;i<n;i++){
        cout<<time[i]<<' ';
    }
    cout<<'\n';
    return 0;
}