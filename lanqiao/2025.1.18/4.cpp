#include<bits/stdc++.h>
//using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n][m]={0},tt;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&tt);
            a[i][j]=tt*9;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==0){
                if(i-1>=0&&i-1<n){
                    a[i][j]+=a[i-1][j]/9;
                }
                if(i+1>=0&&i+1<n){
                    a[i][j]+=a[i+1][j]/9;
                }
                if(j-1>=0&&j-1<m){
                    a[i][j]+=a[i][j-1]/9;
                }
                if(j+1>=0&&j+1<m){
                    a[i][j]+=a[i][j+1]/9;
                }
                if(i-1>=0&&i-1<n&&j-1>=0&&j-1<m){
                    a[i][j]+=a[i-1][j-1]/9;
                }
                if(i-1>=0&&i-1<n&&j+1>=0&&j+1<m){
                    a[i][j]+=a[i-1][j+1]/9;
                }
                if(i+1>=0&&i+1<n&&j-1>=0&&j-1<m){
                    a[i][j]+=a[i+1][j-1]/9;
                }
                if(i+1>=0&&i+1<n&&j+1>=0&&j+1<m){
                    a[i][j]+=a[i+1][j+1]/9;
                }

            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}