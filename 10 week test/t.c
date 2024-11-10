#include <stdio.h>

int main()
{
    int x[121]={1},a;
    for(int i=1;i<121;i++){
        for(int q=i;q<121;q++){
            x[q]+=x[q-i];
        }
    }
    while(scanf("%d",&a)!=EOF){
        printf("%d\n",x[a]);
    }
    return 0;
}