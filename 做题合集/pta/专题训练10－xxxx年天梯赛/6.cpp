#include<bits/stdc++.h>
using namespace std;

int main()
{
    char c;
    int n;
    cin>>c>>n;
    cin.ignore(1,'\n');
    string s[n];
    for(int i=0;i<n;i++){
        getline(cin,s[i]);
    }
    string tt,out;

    for(int i=0;i<n;i++){
        if(i!=0)tt+='\n';
        tt+=s[i];
    }
    out=tt;
    reverse(out.begin(),out.end());
    if(out==tt)cout<<"bu yong dao le\n";
    for(auto &a:out){
        if(a=='@')cout<<c;
        else cout<<a;
    }
    return 0;
}