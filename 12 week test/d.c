#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--){
        char abc[15]={0};
        char a[2][6],c[6];
        for(int i=0; i<3; i++) {
            scanf(" %s%s%s",a[0],a[1],c);
            if(strcmp(c,"even")==0){
                for(int j=0;j<2;j++){
                    for(int h=0;h<4;h++){
                        abc[a[j][h]-'A']=2;
                    }
                }
            }
            else if(strcmp(c,"up")==0){
                for(int j=1;j<=3;j+=2){
                    for(int h=0; h<4; h++){
                        if(abc[a[j][h]-'A']==0){
                            abc[a[j][h]-'A']=j;
                        }
                        else if(abc[a[j][h]-'A']!=j){
                            abc[a[j][h]-'A']=2;
                        }
                    }
                }
            }
            else {
                for(int j=3;j>=1;j-=2){
                    for(int h=0;h<4;h++){
                        if(abc[a[j][h]-'A']==0){
                            abc[a[j][h]-'A']=j;
                        }
                        else if(abc[a[j][h]-'A']!=j){
                            abc[a[j][h]-'A']=2;
                        }
                    }
                }
            }
        }
        for(char j='A';j<='L';j++){
            if(abc[j-'A']==1||abc[j-'A']==3){
                printf("%c is the counterfeit coin and it is %s.\n",j,abc[j-'A']==1?"light":"heavy");
                break;
            }
        }

    }
    return 0;
}