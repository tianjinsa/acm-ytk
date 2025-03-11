#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n1=0,n2=0;
    int n;
    cin>>n;
    while(n--){
        int t;
        cin>>t;
        if(t%2==0){
            n1++;
        }
        else{
            n2++;
        }
    }
    cout<<n1<<" "<<n2;
    return 0;
}