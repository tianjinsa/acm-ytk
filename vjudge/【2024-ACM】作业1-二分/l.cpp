#include<bits/stdc++.h>
using namespace std;
double a,b,c,d;
double f(double x){
    return a*x*x*x+b*x*x+c*x+d;
}
double find_root(double l,double r){
    double mid;
    int n=16;
    while(n--){
        mid=(l+r)/2;
        if(f(mid)*f(l)<=0){
            r=mid;
        } else{
            l=mid;
        }
    }
    return (l+r)/2;
}

int main()
{
    cin>>a>>b>>c>>d;
    vector<double>roots;
    for(double i=-100;i<=100&&roots.size()<3;i+=0.1){
        if(f(i)*f(i+0.1)<0){
            double root=find_root(i,i+0.1);
            roots.push_back(root);
            i=root+0.9;
        }
    }
    sort(roots.begin(),roots.end());
    for(int i=0;i<roots.size();i++){
        printf("%.2f ",roots[i]);
    }
    return 0;
}