#include<bits/stdc++.h>
//using namespace std;
int a[1111],b[1111];

int main()
{
    int n,m;
    while(scanf("%d",&n)&&n){
        memset(b,0,sizeof(b));
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        std::sort(a,a+n);
        scanf("%d",&m);
        if(m<5){
            printf("%d\n",m);
            continue;
        }
        if(m==5){
            printf("%d\n",m-a[n-1]);
            continue;
        }
        for(int i=0;i<n-1;i++){
            for(int j=m-5;j>=a[i];j--){
                b[j]=(b[j]>b[j-a[i]]+a[i])?b[j]:b[j-a[i]]+a[i];
            }
        }
        printf("%d\n",m-b[m-5]-a[n-1]);
    }
    return 0;
}