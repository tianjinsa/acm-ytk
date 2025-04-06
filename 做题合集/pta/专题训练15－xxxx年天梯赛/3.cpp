#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a=0,b=0,t;
    cin>>t;
    while(cin>>t){
        if(t%2){
            a++;
        }
        else{
            b++;
        }
    }
    cout<<a<<' '<<b<<endl;
    return 0;
}