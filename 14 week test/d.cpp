#include<bits/stdc++.h>
//using namespace std;
char a[24][24];
int aa,bb;
void ff(int &sum,int x,int y)
{
    if(x+1<aa&&a[x+1][y]=='0'){
        a[x+1][y]='1';
        sum++;
        ff(sum,x+1,y);
    }
    if(y+1<bb&&a[x][y+1]=='0'){
        a[x][y+1]='1';
        sum++;
        ff(sum,x,y+1);
    }
    if(y-1>=0&&a[x][y-1]=='0'){
        a[x][y-1]='1';
        sum++;
        ff(sum,x,y-1);
    }
    if(x-1>=0&&a[x-1][y]=='0'){
        a[x-1][y]='1';
        sum++;
        ff(sum,x-1,y);
    }
    return;
}
int main()
{
    char cc;
    int xx,yy,sum;
    while(scanf("%d%d",&bb,&aa)!=EOF){
        sum=0;
        for(int i=0;i<aa;i++){
            for(int j=0;j<bb;j++){
                scanf("%c",&cc);
                if(cc=='.'){
                    a[i][j]='0';
                }
                else if(cc=='#'){
                    a[i][j]='9';
                }
                else if(cc=='@'){
                    a[i][j]='1';
                    xx=i;
                    yy=j;
                }
                else if(cc=='\n'){
                    j--;
                }
            }
        }
        ff(sum,xx,yy);
        printf("%d\n",sum);
    }
    return 0;
}