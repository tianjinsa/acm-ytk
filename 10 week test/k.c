#include<stdio.h>
#include <string.h>
int main()
{
    
    int n;
    while (scanf("%d",&n)&&n!=0){
        int x=0,y,a[100]={0},max=0,xx;
        char col[100][16]={0},temp[16];
        getchar();
        for(int i=0;i<n;i++){
            scanf("%s\n",temp);
            y=0;
            for(int k=0;k<x;k++){
                if(strcmp(col[k], temp) == 0){
                    y=1;
                    a[k]++;
                    break;
                }
            }
            if(y==0){
                strcpy(col[x], temp);
                x++;
            }
        }
        for(int i=0;i<x;i++){
            if(a[i]>max){
                max=a[i];
                xx=i;
            }
        }
        printf("%s\n",col[xx]);
    }
    return 0;
}