#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    cin.ignore(1,'\n');
    while(n--){
        string s;
        getline(cin,s);
        if(s[s.size()-1]!='?'){
            cout<<"enen"<<endl;
        }
        else if(s.find("PTA")!=-1){
            cout<<"Yes!"<<endl;
        }
        else{
            cout<<"No."<<endl;
        }
    }
    return 0;
}