#include<stdio.h>
#include<string.h>
void sss(int a[5][6],int i,int j)
{
    a[i][j]=!a[i][j];
    if(j>0){
        a[i][j-1]=!a[i][j-1];
    }
    if(j<5){
        a[i][j+1]=!a[i][j+1];
    }
    if(i>0){
        a[i-1][j]=!a[i-1][j];
    }
    if(i<4){
        a[i+1][j]=!a[i+1][j];
    }
}
int main()
{
    int a[5][6],b[5][6],c[5][6];
    for(int i=0;i<5;i++){
        for(int j=0;j<6;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(b[0][0]=0;b[0][0]<=1;b[0][0]++){
        for(b[0][1]=0;b[0][1]<=1;b[0][1]++){
            for(b[0][2]=0;b[0][2]<=1;b[0][2]++){
                for(b[0][3]=0;b[0][3]<=1;b[0][3]++){
                    for(b[0][4]=0;b[0][4]<=1;b[0][4]++){
                        for(b[0][5]=0;b[0][5]<=1;b[0][5]++){
                            memcpy(c,a,sizeof(c));
                            memset(&b[1][0],0,sizeof(int)*4*6);
                            for(int i=0;i<6;i++){
                                if(b[0][i]){
                                    sss(c,0,i);
                                }
                            }
                            for(int i=0;i<4;i++){
                                for(int j=0;j<6;j++){
                                    if(c[i][j]){
                                        b[i+1][j]=1;
                                        sss(c,i+1,j);
                                    }
                                }
                            }
                            int flag=1;
                            for(int i=0;i<6;i++){
                                if(c[4][i]){
                                    flag=0;
                                    break;
                                }
                            }
                            if(flag){
                                for(int i=0;i<5;i++){
                                    for(int j=0;j<5;j++){
                                        printf("%d ",b[i][j]);
                                    }
                                    printf("%d\n",b[i][5]);
                                }
                                return 0;
                            }
                        }
                    }
                }
            }
        }                   
    }
    return 0;
}
