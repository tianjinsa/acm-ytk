#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[40];
    a[0]=1;
    a[1]=1;
    for(int i=2;i<40;i++)
    {
        a[i]=a[i-1]+a[i-2];
    }
    int n;
    cin>>n;
    double ans=0;
    for(int i=2;i<n+2;i++)
    {
        ans+=1.0*a[i]/a[i-1];
    }
    printf("%.4f\n",ans);
    return 0;
}