#include <stdio.h>

int main()
{
    int n,a,b,c;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d",&a,&b,&c);
        switch (a)
        {
        default:
            b+=(a-6)*8;
        case 6:
            b+=2;
        case 5:
            b+=3;
        case 4:
            b+=4;
        case 3:
            b+=5;
        case 2:
            b+=6;
        case 1:
            b+=7;
        case 0:
            break;
        }
        if(b>c){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}