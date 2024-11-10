#include <stdio.h>

int main()
{
    int a;
    while(scanf("%d",&a)!=EOF){
        if(a<=168){
            printf("CRASH %d",a);
            return 0;
        }
    }
    printf("NO CRASH");
    return 0;
}