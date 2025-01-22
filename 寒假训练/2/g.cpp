#include<bits/stdc++.h>
using namespace std;
int tt;
string sss(const string s){
    if(s.find("1")!=-1&&s.find("0")!=-1){
        return "C"+sss(s.substr(0,s.size()/2))+sss(s.substr(s.size()/2));
    }
    else if(s.find("0")!=-1){
        return "A";
    }
    else{
        return "B";
    }
}
int main()
{
    string s;
    cin>>s;
    cout<<sss(s);
    return 0;
}