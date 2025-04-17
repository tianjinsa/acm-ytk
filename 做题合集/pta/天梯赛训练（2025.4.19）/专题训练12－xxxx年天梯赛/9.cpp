#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int main()
{
    int n,m;
    cin>>n>>m;
    deque<int>kong;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        kong.push_back(t);
    }
    for(int i=0;i<n/m;i++){
        stack<int>st;
        for(int j=0;j<m;j++){
            int t;
            cin>>t;
            st.push(t);
        }
        while(!st.empty()){
            mp[kong.front()]=st.top();
            kong.pop_front();
            st.pop();
        }
    }
    cin>>n;
    while(n--){
        int t;
        cin>>t;
        if(mp.count(t))cout<<mp[t]<<endl;
        else cout<<"Wrong Number\n";
    }
    return 0;
}