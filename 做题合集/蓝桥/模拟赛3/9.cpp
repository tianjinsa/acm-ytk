#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int max=0,t,ans=0;
    for(int i=0;i<n;i++){

        cin>>t;
        if(t>max){
            max=t;
            ans++;
        }
    }
    cout<<ans<<endl;

    return 0;
}