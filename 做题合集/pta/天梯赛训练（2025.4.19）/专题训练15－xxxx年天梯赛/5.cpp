#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int vl[m],tue[m];
    for(int i=0;i<m;i++){
        cin>>vl[i];
    }
    for(int i=0;i<m;i++){
        cin>>tue[i];
    }
    
    while(n--){
        int sum=0;
        int t;
        for(int i=0;i<m;i++){
            cin>>t;
            if(tue[i]==t){
                sum+=vl[i];
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}