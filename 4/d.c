#include<stdio.h>
#include<math.h>
int main()
{
    int a,b;
    double s;
    scanf("%d",&a);
    while(a--){
        scanf("%d",&b);
        s=1;
        for(int i=1;i<=b;i++){
            s+=log10(i);
        }
        printf("%d\n",(int)s);
    }
    return 0;
}