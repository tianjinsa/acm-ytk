#include <stdio.h>

int main()
{
    int n,a[101],max=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        int nb=0,xx=a[i],nc=0,yy=a[i];
        for(int j=i-1;j>=0;j--){
            if(a[j]<xx){
                xx=a[j];
                nb++;
            }
        }
        for(int j=i+1;j<n;j++){
            if(a[j]<yy){
                yy=a[j];
                nc++;
            }
        }
        if(nb+nc>max){
            max=nb+nc;
        }
    }
    printf("%d",n-max-1);
    return 0;
}