#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int sum=max(a,b),ans=a+b;
    cout<<(sum>0?sum:0)<<' '<<(ans>0?ans:0)<<endl;
    if(ans>sum){
        cout<<"^_^";
    }else if(sum<=0){
        cout<<"-_-";
    }
    else{
        cout<<"T_T";
    }
    return 0;
}