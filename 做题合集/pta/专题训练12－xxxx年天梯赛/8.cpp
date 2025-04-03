#include<bits/stdc++.h>
using namespace std;
vector<int> pir(1,2);
void ss(int n){
    for(int i=3;i<n;i+=2){
        for(int j=2;j*j<=i;j++){
            if(i%j==0)goto to;
        }
        pir.push_back(i);
        to:;
    }
}
bool fin(int p,int q,int r){
    if(!binary_search(pir.begin(),pir.end(),p*q+r))return 0;
    if(!binary_search(pir.begin(),pir.end(),q*r+p))return 0;
    if(!binary_search(pir.begin(),pir.end(),r*p+q))return 0;
    return 1;
}
int main()
{
    vector<vector<int>>out;
    int m,n,ans=0;
    cin>>m>>n;
    ss(1000000);
    m=lower_bound(pir.begin(),pir.end(),m)-pir.begin();
    for(int i=m;pir[i]<=n;i++){
        for(int j=i+1;pir[j]<=n;j++){
            for(int k=j+1;pir[k]<=n;k++){
                if(fin(pir[i],pir[j],pir[k])){
                    out.push_back({pir[i],pir[j],pir[k]});
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}