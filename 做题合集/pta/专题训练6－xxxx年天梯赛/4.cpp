#include<bits/stdc++.h>
using namespace std;
bool is_prime(long long n)
{
    if(n==1)return 0;
    for(long long i=2;i*i<=n;i++){
        if(n%i==0) return 0;
    }
    return 1;
}
int main()
{
    int n;
    cin>>n;
    while(n--){
        long long x;
        cin>>x;
        cout<<(is_prime(x)?"Yes":"No")<<endl;
    }
    return 0;
}