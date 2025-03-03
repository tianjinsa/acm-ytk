#include<bits/stdc++.h>
using namespace std;
string sss(double x){
    char buffer[20];
    sprintf(buffer, "%012lf", 2018*x*x*x*x + 21*x + 5*x*x*x + 5*x*x + 14);
    return string(buffer);
}
int main()
{
    string minnum="000000000014",maxnum="201805052114";
    int N;
    cin>>N;
    while(N--)
    {
        string s;
        cin>>s;
        char buffer[20];
        sprintf(buffer, "%012lf",stold(s));
        double cc = stold(buffer);
        if(cc<minnum||cc>maxnum){
            printf("-1\n");
            continue;
        }
        int n=64;
        double l=0,r=100;
        while(n--)
        {
            double mid=l+(r-l)/2;
            if(sss(mid)<s)
                l=mid;
            else
                r=mid;
        }

        printf("%.4lf\n",l);
    }
    
    return 0;
}