#include <stdio.h>

int main()
{
    int all;
    scanf("%d",&all);
    if(all%2){
        printf("0 0");
        return 0;
    }
    printf("%d %d",all/4+(all%4)/2,all/2);
    return 0;
}