#include<bits/stdc++.h>
using namespace std;
double y;
double ss(double x){
    return 6*pow(x,7)+8*pow(x,6)+7*pow(x,3)+5*pow(x,2)-y*x;
}
int main()
{
    int n;
    cin>>n;
    while(n--){
        cin>>y;
        double l=0,r=100,mid1,mid2;
        int nn=32;
        while(nn--){
            mid1=(l+r)/3;
            mid2=(l+r)/3*2;
            if(ss(mid1)<ss(mid2)){
                r=mid2;
            }else{
                l=mid1;
            }
        }
        cout<<fixed<<setprecision(4)<<ss(l)<<endl;
    }
    return 0;
}