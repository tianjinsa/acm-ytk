#include<bits/stdc++.h>
//using namespace std;

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int pl[a+2][b+2]={0};
    int c,x,y;
    scanf("%d",&c);
    for(int i=0;i<c;i++){
        scanf("%d%d",&x,&y);
        pl[x][y]=1;
    }
    for(int cc=1;cc<c;cc++){
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                if(pl[i][j]==cc){
                    pl[i-1][j]=cc+1;
                    pl[i+1][j]=cc+1;
                    pl[i][j-1]=cc+1;
                    pl[i][j+1]=cc+1;
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(pl[i][j]){
                ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}