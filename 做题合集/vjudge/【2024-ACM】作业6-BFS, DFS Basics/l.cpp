#include<bits/stdc++.h>
using namespace std;

vector<string> mp;
int m,n;

int dx[]={-1,1,0,0,-1,1,-1,1};
int dy[]={0,0,-1,1,-1,-1,1,1};

void dfs(int x,int y){
    
    for(int i=0;i<8;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        
        if(nx >= 0&&nx<m&&ny >= 0&&ny<n&&mp[nx][ny]=='@'){
            mp[nx][ny]='*';
            dfs(nx,ny);
        }
    }
}

int main(){
    while(cin>>m>>n&&m){
        mp.resize(m);
        for(int i=0;i<m;i++){
            cin>>mp[i];
        }
        int nn=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mp[i][j]=='@'){
                    dfs(i,j);
                    nn++;
                }
            }
        }
        cout<<nn<<endl;
    }
    return 0;
}