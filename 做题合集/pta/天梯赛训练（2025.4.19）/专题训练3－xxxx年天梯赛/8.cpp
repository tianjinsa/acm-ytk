#include<bits/stdc++.h>
using namespace std;

int main()
{
    int d;
    cin>>d;
    int t=(d+2)%7;
    if (t==0){
        t=7;
    }
    cout<<t<<endl;
    return 0;
}