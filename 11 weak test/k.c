#include <stdio.h>

int main()
{
    int n,p,m;
    char xx[305][20];
    while (~scanf("%d\n",&n)&&n!=0)
    {
        for(int i=0;i<n;i++)
        {
            fgets(xx[i],20,stdin);
        }
        scanf("%d,%d",&p,&m);
        int nn=0;
        int mm=0;
        p--;
        while(nn<=n-1){
            if(p==n){
                p=0;
            }
            if(xx[p][0]!='\0'){
                mm++;
                if(mm==m){
                    printf("%s",xx[p]);
                    xx[p][0]='\0';
                    mm=0;
                    nn++;
                }
            }
            p++;
        }
        // for(int i=0;i<n;i++){
        //     if(xx[i]!=0){
        //         printf("%d\n",xx[i]);
        //     }
        // }
    }
    
    return 0;
}