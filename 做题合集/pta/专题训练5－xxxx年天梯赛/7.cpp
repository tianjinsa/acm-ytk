#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,n,minl=INT_MAX,xx=0;
    cin>>a>>b>>n;
    for(int i=1;i<=a/2&&i<n;i++){
        if(a%i==0&&b>(n-i)&&b%(n-i)==0){
            int t=abs(a/i-b/(n-i));
            if(t<minl){
                minl=t;
                xx=i;
            }
        }
    }
    if(xx==0){
        cout<<"No Solution"<<endl;
    }
    else{
        cout<<xx<<' '<<n-xx<<endl;
    }
    return 0;
}