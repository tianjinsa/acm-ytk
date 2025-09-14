#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int r1=1001,c1=1001,r2=-1,c2=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int p;
            cin>>p;
            if(p==0){
                r1=min(r1,i);
                c1=min(c1,j);
                r2=max(r2,i);
                c2=max(c2,j);
            }
        }
    }
    cout<<max(0,r2-r1-1)*max(0,c2-c1-1);
    return 0;
}
