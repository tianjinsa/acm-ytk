#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,t1,t2,t3;
    cin>>a>>b>>t1>>t2>>t3;
    if(t1+t2+t3==0){
        cout<<"The winner is a: "<<a<<" + 3";
        return 0;
    }
    else if(t1+t2+t3==3){
        cout<<"The winner is b: "<<b<<" + 3";
        return 0;
    }
    if(a>b){
        cout<<"The winner is a: "<<a<<" + "<<3-t1-t2-t3;
    }
    else{
        cout<<"The winner is b: "<<b<<" + "<<t1+t2+t3;
    }
    return 0;
}