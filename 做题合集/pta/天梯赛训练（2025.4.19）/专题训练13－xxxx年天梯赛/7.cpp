#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long s=1,n=1,a;
    cin>>a;
    while(s<a){
        s=s*10+1;
        n++;
    }
    while(s){
        cout<<s/a;
        s%=a;
        if(s==0)break;
        s=s*10+1;
        n++;
    }
    cout<<' '<<n;

    return 0;
}