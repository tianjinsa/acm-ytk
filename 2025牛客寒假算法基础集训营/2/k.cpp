#include<bits/stdc++.h>
using namespace std;
char a[500+2][500+2]={0};
map<int,int> mp;
void sss(const int x,const int y){
    a[x][y]=0;
    if(a[x+1][y]=='0'&&mp.find((x+1)*505+y)==mp.end()){
        mp[(x+1)*505+y]=1;
    }
    else if(a[x+1][y]=='1'){
        sss(x+1,y);
    }
    if(a[x-1][y]=='0'&&mp.find((x-1)*505+y)==mp.end()){
        mp[(x-1)*505+y]=1;
    }
    else if(a[x-1][y]=='1'){
        sss(x-1,y);
    }
    if(a[x][y+1]=='0'&&mp.find(x*505+y+1)==mp.end()){
        mp[x*505+y+1]=1;
    }
    else if(a[x][y+1]=='1'){
        sss(x,y+1);
    }
    if(a[x][y-1]=='0'&&mp.find(x*505+y-1)==mp.end()){
        mp[x*505+y-1]=1;
    }
    else if(a[x][y-1]=='1'){
        sss(x,y-1);
    }
    return;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    memset(a,1,sizeof(a));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf(" %c",&a[i][j]);
        }
    }
    int ans=500*500;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='1'){
                sss(i,j);
                ans=min(ans,(int)mp.size());
                mp.clear();
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}