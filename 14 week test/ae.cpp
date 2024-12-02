#include<stdio.h>
int main()
{
    long long a[10005];
    a[1]=2;
    for(int i=2;i<=10001;i++){
        a[i]=a[i-1]+4*(i-1)+1;
    }
    int n,x;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        printf("%lld\n",a[x]);
    }
    return 0;
}