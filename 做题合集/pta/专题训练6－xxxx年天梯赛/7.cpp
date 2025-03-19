#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--){
        double a,b;
        cin>>a>>b;
        a=(a-100)*1.8;
        if(abs(a-b)<a*0.1){
            cout<<"You are wan mei!"<<endl;
        }
        else if(a-b<0){
            cout<<"You are tai pang le!"<<endl;
        }
        else{
            cout<<"You are tai shou le!"<<endl;
        }
    }
    return 0;
}