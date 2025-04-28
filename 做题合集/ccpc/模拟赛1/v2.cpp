#include <bits/stdc++.h>
using namespace std;
long long apls(int x)
{
    if(x==0)return 0;
    long long z=1;
    for(int i=x;i>0;i--){
        z*=i;
    }
    return z;
}
long long cpls(int n,int k)
{
    if(k>n-k)k=n-k;
    long long xx=1;
    for(int i=0;i<k;i++){
        xx*=(n-i);
        xx/=(i+1);
    }
    return xx;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int a = n % m;       // 大份额类型个数
    int b = m - a;       // 小份额类型个数
    double p1 = (1.0 * (n/m)) / n;                 // 小份额类型概率
    double p2 = (1.0 * (n/m + (n%m!=0))) / n;      // 大份额类型概率

    const double EPS = 1e-15;
    double sum = 0;
    // E = sum_{t=0..∞} P(T > t) = sum_{t=0..∞} [1 - ∏_i (1 - (1 - p_i)^t)]
    for(int t=0; ; ++t) {
        double q1 = pow(1 - p1, t);
        double q2 = pow(1 - p2, t);
        double probAll = pow(1 - q1, b) * pow(1 - q2, a);
        double pTgt = 1 - probAll;    // P(T > t)
        if(pTgt < EPS) break;
        sum += pTgt;
    }

    cout<<fixed<<setprecision(10)<<sum<<"\n";
    return 0;
}