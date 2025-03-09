#include<stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    for(int i=2;i<=a;i++){
        for(int j=2;j<=a;j++){
            for(int k=j;k<=a;k++){
                for(int l=k;l<=a;l++){
                    if(i*i*i==j*j*j+k*k*k+l*l*l){
                        printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,l);
                    }
                }
            }
        }
    }
    return 0;
}