#include<bits/stdc++.h>
//using namespace std;
int a[1111];
bool fl[1111];
int main()
{
    int n,m,mt,minx;
    while(scanf("%d",&n)&&n){
        int min=0x7fffffff;
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
        }
        for(int i=0;i<n;i++){
            mt=m;
            for(int j=i;mt-a[i]>=5&&j<n;j++){
                mt-=a[j];
                if(j==n-1){
                    fl[i]=1;
                }
            }
            if(mt<=min){
                min=mt;
                minx=i;
                if(min==5){
                    break;
                }
            }
        }
        if(fl[minx]==0){
            min-=a[n-1];
        }
        else{
            min-=a[minx-1];
        }
        printf("%d\n",min);
    }
    return 0;
}