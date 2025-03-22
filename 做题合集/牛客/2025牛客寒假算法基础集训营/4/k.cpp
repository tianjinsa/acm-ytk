#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    while(N--){
        long long x,y,z,a,b,c;
        cin>>x>>y>>z>>a>>b>>c;
        long long max1=x*a;
        max1=max(max1,y*b);
        max1=max(max1,z*c);
        cout<<max1<<endl;
    }
    return 0;
}