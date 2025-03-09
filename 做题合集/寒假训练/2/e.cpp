#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int tt;
    if((tt=s.find("."))!=-1){
        string t=s.substr(tt+1);
        s=s.substr(0,tt);
        t=to_string(stoll(t));
        reverse(t.begin(),t.end());
        reverse(s.begin(),s.end());
        cout<<stoll(s)<<"."<<stoll(t);
    }
    else if((tt=s.find("/"))!=-1){
        string t=s.substr(tt+1);
        s=s.substr(0,tt);
        reverse(t.begin(),t.end());
        reverse(s.begin(),s.end());
        cout<<stoll(s)<<"/"<<stoll(t);
    }
    else if(s.find("%")!=-1){
        long long a;
        s.erase(s.size()-1,1);
        reverse(s.begin(),s.end());
        cout<<stoll(s)<<"%";
    }
    else{
        long long a;
        reverse(s.begin(),s.end());
        cout<<stoll(s);
    }
    return 0;
}