#include <stdio.h>

int main()
{
    int n,p,m,xx[305];
    while (~scanf("%d %d %d",&n,&p,&m)&&n!=0)
    {
        for(int i=0;i<n;i++)
        {
            xx[i]=i+1;
        }
        int nn=0;
        int mm=0;
        p--;
        while(nn<n-1){
            if(p==n){
                p=0;
            }
            if(xx[p]!=0){
                mm++;
                if(mm==m){
                    printf("%d,",xx[p]);
                    xx[p]=0;
                    mm=0;
                    nn++;
                }
            }
            p++;
        }
        for(int i=0;i<n;i++){
            if(xx[i]!=0){
                printf("%d\n",xx[i]);
            }
        }
    }
    
    return 0;
}