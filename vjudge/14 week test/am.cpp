#include<stdio.h>
int main()
{
    int n,a,b;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        b=3;
        scanf("%d",&a);
        for(int p=0;p<a;p++){
            b=(b-1)*2;
        }
        printf("%d\n",b);
    }
    return 0;
}