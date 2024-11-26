#include<stdio.h>

int main()
{
    int n,m;
    char ch[101][101];
    scanf("%d",&n);
    while(n--){
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%s",ch[i]);
        }
    }
    return 0;
}