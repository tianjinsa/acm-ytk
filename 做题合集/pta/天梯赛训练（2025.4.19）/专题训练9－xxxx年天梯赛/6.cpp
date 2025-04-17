#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin>>x;
    int nn=1,n=1;
    while(n<x){
        n*=10;
        n+=1;
        nn++;
    }
    while(1){
        cout<<n/x;
        n%=x;
        if(n==0)break;
        n*=10;
        n++;
        nn++;
    }
    cout<<' '<<nn;
    
    return 0;
}