#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int Q;
    cin>>Q;
    priority_queue<long long,vector<long long>,greater<long long>> pq;
    long long all=0;
    for(int i=0;i<Q;i++){
        int t;
        cin>>t;
        if(t==1){
            long long x;
            cin>>x;
            pq.push(x-all);
        }
        else if(t==2){
            long long x;
            cin>>x;
            all+=x;
        }
        else{
            long long v=pq.top()+all;
            cout<<v<<'\n';
            pq.pop();
        }
    }
    return 0;
}