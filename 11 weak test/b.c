#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    while (n--)
    {
        int all;
        scanf("%d",&all);
        if(all%2){
            printf("0 0\n");
            continue;
        }
        printf("%d %d\n",all/4+(all%4)/2,all/2);
    }
    
    return 0;
}