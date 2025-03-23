#include<bits/stdc++.h>
using namespace std;
set<int>c,r;
int main()
{
    long long N,M,Q;
    cin>>N>>M>>Q;
    while(Q--){
        int a,b;
        cin>>a>>b;
        if(a){
            c.insert(b);
        }
        else{
            r.insert(b);
        }
    }
    cout<<N*M-(c.size()*N+r.size()*M-c.size()*r.size());
    return 0;
}