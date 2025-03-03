#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,max=0,min=100,sum=0,t;
    cin>>n;
    
    for(int i = 0; i < n; i++) {
        cin >> t;
        sum += t;
        if (t > max) max = t;
        if (t < min) min = t;
    }
    printf("%d\n%d\n%.2lf",max,min,1.0*sum/n);


    return 0;
}