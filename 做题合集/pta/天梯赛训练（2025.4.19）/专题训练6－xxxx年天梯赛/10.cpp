#include<bits/stdc++.h>
using namespace std;
set<int>dq;
int main()
{
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        bool fl=1;
        auto it=dq.upper_bound(x);
        if(it!=dq.end()){
            fl=0;
            dq.erase(it);
            dq.insert(x);
        }
        if(fl){
            dq.insert(x);
        }
    }
    cout<<dq.size();
    return 0;
}