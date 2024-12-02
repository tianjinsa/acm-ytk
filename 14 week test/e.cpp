#include<bits/stdc++.h>
//using namespace std;
long long a[55];
void f()
{
    a[0]=0;
    a[1]=1;
    for(int i=2;i<55;i++){
        a[i]=a[i-1]+a[i-2];
    }
}
int main()
{
    int n;
    f();
    while(scanf("%d",&n)){
        if(n<0||n>50){
            break;
        }
        printf("%lld\n",a[n]);
    }
    return 0;
}