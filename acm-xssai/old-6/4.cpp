#include<bits/stdc++.h>
//using namespace std;
int abc[500][500];
void clean(int a,int b,int x,int y)
{
    for(int i=a;i<=x;i++){
        for(int j=b;j<=y;j++){
            abc[i][j]=0;
        }
    }
}
int chack(int a,int b,int x,int y)
{
    for(int i=a;i<a+x;i++){
        for(int j=b;j<b+y;j++){
            if(abc[i][j]==0){
                clean(a,b,i,j);
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--){
        int a,b,x,y;
        scanf("%d%d",&a,&b);
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                scanf("%d",&abc[i][j]);
            }
        }
        bool fl=0;
        scanf("%d%d",&x,&y);
        for(int i=0;i<=a-x;i++){
            for(int j=0;j<=b-y;j++){
                if(abc[i][j]==1&&chack(i,j,x,y)){
                    fl=1;
                    goto to;
                }
            }
        }
        to:
        if(fl){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }
    return 0;
}