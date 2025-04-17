#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,string>a,pair<int,string>b){
    return a>b;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<pair<int,string>>st;
    int n;
    cin>>n;
    while(n--){
        unordered_set<int>tt;
        string na;
        cin>>na;
        int m,t;
        cin>>m;
        while(m--){
            cin>>t;
            tt.insert(t);
        }
        st.push_back({tt.size(),na});
    }
    while(st.size()<3){
        st.push_back({0,"-"});
    }
    sort(st.begin(),st.end(),cmp);
    bool fl=0;
    for(int i=0;i<3;i++){
        if(fl)cout<<' ';
        else fl=1;
        cout<<st[i].second;
    }
    return 0;
}