#include<bits/stdc++.h>
//using namespace std;
char map[100][100];
int aa,bb;
int min(int x,int y)
{
    int z=100000000;
    if(x+1<aa&&z>map[x+1][y]) z=map[x+1][y];
    if(y+1<bb&&z>map[x][y+1]) z=map[x][y+1];
    if(y-1>=0&&z>map[x][y-1]) z=map[x][y-1];
    if(x-1>=0&&z>map[x-1][y]) z=map[x-1][y];
    return (z-'0'==1)?0:z-'0';
}
void ff(int x,int y)
{
    bool fl1=false,fl2=false,fl3=false,fl4=false;
    if(x+1<aa&&map[x+1][y]!='X'){
        map[x+1][y]+=min(x+1,y);
        fl1=true;
    }
    if(y+1<bb&&map[x][y+1]!='X'){
        map[x][y+1]+=min(x,y+1);
        fl2=true;
    }
    if(y-1>=0&&map[x][y-1]!='X'){
        map[x][y-1]+=min(x,y-1);
        fl3=true;
    }
    if(x-1>=0&&map[x-1][y]!='X'){
        map[x-1][y]+=min(x-1,y);
        fl4=true;
    }
    if(fl1) ff(x+1,y);
    if(fl2) ff(x,y+1);
    if(fl3) ff(x,y-1);
    if(fl4) ff(x-1,y);
    return;
}
int main()
{
    char c;
    while(scanf("%d%d",&aa,&bb)!=EOF){
        for(int i=0;i<aa;i++){
            for(int j=0;j<bb;j++){
                scanf("%c",&c);
                if(c=='\n') j--;
                else if(c=='.'){
                    map[i][j]='1';
                }
                else if(c=='X'){
                    map[i][j]='X';
                }
                else{
                    map[i][j]=c+1;
                }
            }
        }
        map[0][0]+=1;
        ff(0,0);
        printf("%d\n",map[aa-1][bb-1]-'0');
    }
    return 0;
}