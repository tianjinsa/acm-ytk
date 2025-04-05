#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    while(m--){
        int sum=0;
        char t;
        for(int i=n-1;i>=0;--i){
            cin>>t;
            sum+=(t=='n')*pow(2,i);
        }
        cout<<sum+1<<endl;
    }

    return 0;
}