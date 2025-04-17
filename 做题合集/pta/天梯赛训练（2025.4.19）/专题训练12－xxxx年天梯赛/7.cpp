#include<bits/stdc++.h>
using namespace std;
int k,t=0;
int ss(){
    t++;
    if(t>k)t=1;
    return t;
}
int main()
{
    int x,n;
    cin>>n>>k>>x;
    map<int,int>vv;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int y;
            cin>>y;
            if(j%2){
                int tt=ss();
                for(int k=0;k<tt&&i==0;k++){
                    vv[k+i]+=x;
                }
                vv[tt+i]+=y;
            }
            else{
                vv[i]+=y;
            }
        }
        t=0;
    }
    cout<<vv[0];
    for(int i=1;i<n;i++){
        cout<<' '<<vv[i];
    }
    return 0;
}