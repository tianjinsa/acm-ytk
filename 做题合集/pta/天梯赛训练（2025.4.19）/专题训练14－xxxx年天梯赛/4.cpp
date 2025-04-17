#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    double sum;
    cin>>n;
    m=n;
    while(n--){
        double t;
        cin>>t;
        sum+=1/t;
    }
    sum/=m;
    cout<<fixed<<setprecision(2)<<1/sum;
    return 0;
}