#include<bits/stdc++.h>
using namespace std;
double w0,w;
int m;
bool sss(double q){
    return (pow(1.0/(1.0+q),m)>=1-w0/w*q);
}
int main()
{
    cin>>w0>>w>>m;
    double l=0,r=3;
    while(r-l>1e-9){ 
        double mid=l+(r-l)/2;
        if(sss(mid)){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    printf("%.1lf\n",l*100);
    return 0;
}