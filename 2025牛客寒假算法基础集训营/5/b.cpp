#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    long long n,t,k;
    while(N--)
    {
        cin>>n>>t>>k;
        cout<<min((n-k)/t,k+1)<<endl;
    }
    return 0;
}