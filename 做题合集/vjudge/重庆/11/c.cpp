#include<bits/stdc++.h>
using namespace std;

int main()
{
    int Q;
    cin>>Q;
    deque<pair<long long,long long>> dq;
    while(Q--){
        int t;
        cin>>t;
        if(t==1){
            long long c,x;
            cin>>c>>x;
            dq.emplace_back(x,c);
        }
        else{
            long long k;
            cin>>k;
            long long res=0;
            while(k>0){
                auto &p=dq.front();
                long long cnt=p.second,val=p.first;
                if(cnt<=k){
                    res+=cnt*val;
                    k-=cnt;
                    dq.pop_front();
                }
                else{
                    res+=k*val;
                    p.second-=k;
                    k=0;
                }
            }
            cout<<res<<'\n';
        }
    }
    return 0;
}