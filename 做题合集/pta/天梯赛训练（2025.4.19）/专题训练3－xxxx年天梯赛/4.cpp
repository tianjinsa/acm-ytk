#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int>st;
    int n;
    cin>>n;
    while(n--){
        int k;
        cin>>k;
        if(k==1){
            cin>>k;
            continue;
        }
        while(k--){
            int t;
            cin>>t;
            st.insert(t);
        }
    }
    cin>>n;
    bool fl=0;
    while(n--){
        int t;
        cin>>t;
        if(st.find(t)==st.end()){
            if(fl){
                cout<<" ";
            }
            printf("%05d",t);
            fl=1;
            st.insert(t);
        }
    }
    if(fl==0){
        cout<<"No one is handsome";
    }
    return 0;
}