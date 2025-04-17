#include<bits/stdc++.h>
using namespace std;

int main()
{
    double a,b;
    bool fl;
    cin>>a>>fl>>b;
    a=a*(fl?1.26:2.455);
    cout<<fixed<<setprecision(2)<<a<<' ';
    if(a>b)cout<<"T_T";
    else cout<<"^_^";
    return 0;
}