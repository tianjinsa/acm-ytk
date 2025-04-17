#include<bits/stdc++.h>
using namespace std;
long long ss(long long a){
    long long ans=1;
    while(a--){
        ans*=a+1;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    long long ans=0;
    for(int i=1;i<=n;i++){
        ans+=ss(i);
    }
    cout<<ans;
    return 0;
}