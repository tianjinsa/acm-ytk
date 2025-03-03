#include<bits/stdc++.h>
using namespace std;

int main()
{
    double s,a,b;
    cin>>s>>a>>b;
    double c=(a+b)*s/(a*3+b);
    printf("%.6lf",c/b+(s-c)/a);
    return 0;
}