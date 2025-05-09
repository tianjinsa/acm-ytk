#include<bits/stdc++.h>
using namespace std;
vector<bool> flg;
int main()
{
    long long n;
    cin>>n;
    flg.resize(n+10,1);
    list<tuple<long long,long long,long long,long long>>chong;
    for(long long i=0;i<n;i++){
        long long t;
        cin>>t;
        if(t==1){
            long long x,y,h;
            cin>>x>>y>>h;
            chong.push_back({x,y,h,i});
        }else if(t==2){
            long long x,y,atk,r;
            cin>>x>>y>>atk>>r;
            if(chong.empty()){
                continue;
            }
            long long minx,miny;
            long long dis=LLONG_MAX;
            for(auto it=chong.begin(); it!=chong.end(); ++it){
                auto [cx,cy,ch,ii]=*it;
                long long dx = cx - x;
                long long dy = cy - y;
                long long distance = dx * dx + dy * dy;
                if(distance < dis){
                    dis = distance;
                    minx = cx;
                    miny = cy;
                }
            }
            long long hh=0;
            for(auto it=chong.begin(); it!=chong.end();){
                auto &[cx,cy,ch,ii]=*it;
                long long dx = cx - minx;
                long long dy = cy - miny;
                long long distance = dx * dx + dy * dy;
                auto it2=it;
                it++;
                if(distance<=r*r){
                    ch-=atk*3;
                    if(ch <= 0){
                        flg[ii]=0;
                        chong.erase(it2);
                    }
                    hh=max(hh,ch);
                }
            }
            if(hh>0){
                flg[i]=0;
            }
        }
    }
    for(long long i=0;i<n;i++){
        cout<<(flg[i]?"Yes":"No")<<endl;
    }
    return 0;
}