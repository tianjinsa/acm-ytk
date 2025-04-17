#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    string t,t2;
    for (int i=1;i<a.length();i++){
        if(a[i]%2==a[i-1]%2){
          t+=max(a[i],a[i-1]);
        }
    }
    cout<<t<<endl;
    for (int i=1;i<b.length();i++){
        if(b[i]%2==b[i-1]%2){
          t2+=max(b[i],b[i-1]);
        }
    }
    if(t!=t2)cout<<t2;
    return 0;
}