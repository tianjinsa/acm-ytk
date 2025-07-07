#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int Q;
    cin>>Q;
    queue<long long> q;
    priority_queue<long long,vector<long long>,greater<long long>> pq;
    for(int i=0;i<Q;i++){
        int c;
        cin>>c;
        if(c==1){
            long long x;
            cin>>x;
            q.push(x);
        }
        else if(c==2){
            long long ans;
            if(!pq.empty()){
                ans=pq.top();
                pq.pop();
            }
            else{
                ans=q.front();
                q.pop();
            }
            cout << ans << '\n';
        }
        else if(c==3){
            while(!q.empty()){
                pq.push(q.front());
                q.pop();
            }
        }
    }
    return 0;
}