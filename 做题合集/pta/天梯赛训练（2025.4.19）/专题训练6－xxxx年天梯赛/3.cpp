#include<bits/stdc++.h>
using namespace std;
set<char>st;
int main()
{
    string s,t="";
    cin>>s;
    for(auto i:s){
        st.insert(i);
    }
    vector<char>v(st.begin(),st.end());
    reverse(v.begin(), v.end());
    cout<<"int[] arr = new int[]{";
    bool fl=0;
    for(auto i:v){
        if(fl)cout<<",";
        t+=i;
        fl=1;
        cout<<i;
    }
    cout<<"};"<<endl;
    cout<<"int[] index = new int[]{";
    
    fl=0;
    for(auto i:s){
        if(fl)cout<<",";
        fl=1;
        cout<<t.find(i);
    }
    cout<<"};"<<endl;
    return 0;
}