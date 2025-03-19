#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    char c;
    cin>>n>>c;
    string s;
    cin.ignore(1,'\n');
    getline(cin,s);
    int t=s.size();
    if(t<=n){
        for(int i=0;i<n-t;i++){
            s=c+s;
        }
    }
    else{
        s=s.substr(t-n);
    }
    cout<<s<<endl;
    return 0;
}