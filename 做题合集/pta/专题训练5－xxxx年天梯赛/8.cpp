#include<bits/stdc++.h>
using namespace std;
int ssum(int n){
    int sum=0;
    while(n){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int main()
{
    int n;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        int sa=ssum(a),sb=ssum(b);
        bool fla=(a%sb==0),flb=(b%sa==0);
        if(fla&&!flb){
            cout<<"A"<<endl;
        }
        else if(flb&&!fla){
            cout<<"B"<<endl;
        }
        else{
            cout<<(a>b?"A":"B")<<endl;
        }
    }
    return 0;
}