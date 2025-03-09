#include <stdio.h>

int main()
{
    int n,a,xx,ss;
    while (scanf("%d",&n)&&n!=0)
    {
        ss=0;
        xx=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            ss+=((a-xx)>0)?((a-xx)*6):((a-xx)*(-4));
            ss+=5;
            xx=a;
        }
        printf("%d\n",ss);
    }
    
   return 0;
}