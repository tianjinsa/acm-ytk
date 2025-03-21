#include<bits/stdc++.h>
using namespace std;
long long ss(int n)
{
    long long ans=1;
    for(int i=1;i<=n;i++){
        ans*=i;
    }
    return ans;
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<ss(a+b);
    return 0;
}