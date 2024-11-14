#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    while(n--){
        int a[52]={0,1},x,y;
        scanf("%d%d",&x,&y);
        y-=x-1;
        for(int i=2;i<=y;i++){
            a[i]=a[i-1]+a[i-2];
        }
        printf("%d\n",a[y]);
    }
    
    return 0;
}