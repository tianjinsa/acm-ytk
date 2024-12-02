#include<bits/stdc++.h>
//using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)&&n){
        long long a=1,b=0,c=0,d=0;
        for(int i=1;i<n;i++){
            a+=d;
            d=c;
            c=b;
            b=a;
        }
        printf("%lld\n",a+b+c+d);
    }
    return 0;
}