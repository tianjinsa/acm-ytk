#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m,n;
    cin>>m>>n;
    queue<int> mq;
    queue<int> wq;
    for(int i=1;i<=m;++i){
        mq.push(i);
    }
    for(int i=1;i<=n;++i){
        wq.push(i);
    }
    int k;
    cin>>k;
    while(k--){
        int man=mq.front();
        mq.pop();
        int wom=wq.front();
        wq.pop();
        cout<<man<<" "<<wom<<"\n";
        mq.push(man);
        wq.push(wom);
    }
    return 0;
}
