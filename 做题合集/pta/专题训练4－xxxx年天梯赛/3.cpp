#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,k;
    string s;
    cin>>n>>s>>m>>k;
    if(k==n){
        cout<<"mei you mai "+s+" de"<<endl;
    }
    else if(k==m){
        cout<<"kan dao le mai "+s+" de"<<endl;
    }
    else{
        cout<<"wang le zhao mai "+s+" de"<<endl;
    }
    return 0;
}