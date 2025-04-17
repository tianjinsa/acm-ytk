#include<bits/stdc++.h>
using namespace std;
vector<pair<int,string>>vec;
int main()
{
    int n;
    cin>>n;
    vec.resize(n);
    for(int i=0;i<n;i++){
        cin>>vec[i].second;
        int k;
        cin>>k;
        unordered_set<int>st;
        while(k--){
            int t;
            cin>>t;
            st.insert(t);
        }
        vec[i].first=st.size();
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<3;i++){
        if(i)cout<<' ';
        if(i+1>n)cout<<'-';
        else cout<<vec[n-i-1].second;
    }

    return 0;
}