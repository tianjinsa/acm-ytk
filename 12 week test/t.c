#include<stdio.h>
#include<stdbool.h>
int main()
{
    int n,a[101],nn=0,xx;
    while(scanf("%d",&n)!=EOF){
        bool b[20005]={0};
        xx=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n&&!xx;i++){
            if(a[i]<a[i-1]||a[i]<1){
                xx=1;
                break;
            }
            for(int j=i;j<=n&&!xx;j++){
                if(b[a[i]+a[j]]){
                    xx=1;
                    break;
                }
                b[a[i]+a[j]]=1;
            }
        }
        if(xx){
            printf("Case #%d: It is not a B2-Sequence.\n\n",++nn);
            continue;
        }
        printf("Case #%d: It is a B2-Sequence.\n\n",++nn);
    }
    return 0;
}