#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long ans=0;
    while(n--){
        int a,b;
        cin>>a>>b;
        if(a<b)ans++;
    }
    cout<<ans;
    return 0;
}