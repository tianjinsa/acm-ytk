#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    double sum=0;
    cin>>n;
    set<pair<int,string>>st;
    for(int i=0;i<n;i++){
        string s;
        int sc;
        cin>>s>>sc;
        sum+=sc;
        st.insert({sc,s});
    }
    int out=sum/(n*2);
    auto [a1,s1]=*st.upper_bound({out,""});
    auto [a2,s2]=*prev(st.upper_bound({out,""}));
    if(abs(a1-out)>abs(out-a2)){
        cout<<out<<" "<<s2;
    }
    else{
        cout<<out<<" "<<s1;
    }
    return 0;
}