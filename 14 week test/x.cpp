#include<bits/stdc++.h>
//using namespace std;
long long aa[21];
void f()
{
    aa[0]=1;
    aa[1]=1;
    for(int i=2;i<21;i++){
        aa[i]=aa[i-1]+aa[i-2];
    }
}
int main()
{
    int n;
    f();
    scanf("%d",&n);
    while(n--)
    {
        int a;
        scanf("%d",&a);
        for(int i=0;i<a-1;++i)
            printf("%lld ",aa[i]);
        printf("%lld\n",aa[a-1]);
    }
    return 0;
}