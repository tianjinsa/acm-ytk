#include<bits/stdc++.h>
//using namespace std;
int main()
{
    printf("N=2: 0\n");
    for(int n=3;n<=31;n++){
        printf("n=%d: %.0Lf\n",n,(long double)pow(4,n-3)*2*(n-2)*(n-1)*2);
    }
    return 0;
}