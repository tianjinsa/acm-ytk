#include<bits/stdc++.h>
//using namespace std;

int main()
{
    long double a=1;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        a*=2;
    }
    printf("%.0Lf\n",a);
    return 0;
}