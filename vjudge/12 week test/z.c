#include<stdio.h>

int main()
{
    int n,m,ty;
    scanf("%d%d%d",&n,&m,&ty);
    switch (ty)
    {
    case 0:
        printf("%d",n);
        return 0;
    case 1:
        printf("%d",m);
        return 0;
    case 2:
        printf("%d",n);
        return 0;
    }
    int a[101]={0},t,xx=0;
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        if(t){
            a[i]=1;
        }
    }
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        if(t){
            a[i]++;
            if(a[i]==2){
                xx++;
            }
        }
    }
    if(xx>=m){
        printf("%d",n-xx+m);
    }
    else{
        printf("%d",n);
    }
    return 0;
}