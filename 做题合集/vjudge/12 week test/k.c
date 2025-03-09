#include<stdio.h>

int main()
{
    char ch[51][51];
    int a,b,xx=0,nn[51][3]={0};
    scanf("%d %d",&a,&b);
    for(int i=0;i<a;i++){
        scanf("%s",ch[i]);
    }
    for(int i=0;i<b;i++){
        if(ch[0][i]!='W'){
            xx++;
        }
        if(ch[a-1][i]!='R'){
            xx++;
        }
    }
    for(int i=1;i<a-1;i++){
        for(int j=0;j<b;j++){
            if(ch[i][j]=='W'){
                nn[i][0]++;
            }
            else if(ch[i][j]=='B'){
                nn[i][1]++;
            }
            else{
                nn[i][2]++;
            }
        }
    }
    int min=9999,xx1;
    for(int i=1;i<a-1;i++){
        for(int j=i;j<a-1;j++){
            xx1=0;
            for(int k=1;k<i;k++){
                xx1+=nn[k][1]+nn[k][2];
            }
            for(int k=i;k<=j;k++){
                xx1+=nn[k][0]+nn[k][2];
            }
            for(int k=j+1;k<a-1;k++){
                xx1+=nn[k][0]+nn[k][1];
            }
            if(xx1<min){
                min=xx1;
            }
        }
    }
    printf("%d",min+xx);
    return 0;
}