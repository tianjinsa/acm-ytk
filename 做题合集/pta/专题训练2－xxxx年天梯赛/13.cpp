#include<bits/stdc++.h>
using namespace std;
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};

vector<vector<int>> mp;
int m,n;
int aim_x,aim_y;
int ss(int x,int y){
    vector<vector<bool>>end(m,vector<bool>(n,0));
    queue<tuple<int,int,int>> q;
    q.push({x,y,0});
    end[x][y]=1;
    while(!q.empty()){
        auto [xx,yy,time]=q.front();
        q.pop();
        if(xx==aim_x&&yy==aim_y){
            return time;
        }
        for(int dir=0;dir<4;dir++){
            int nx=xx+dx[dir];
            int ny=yy+dy[dir];
            if(nx>=0&&nx<m&&ny>=0&&ny<n&&(mp[nx][ny]==1||mp[nx][ny]==2)&&!end[nx][ny]){
                end[nx][ny]=1;
                q.push({nx,ny,time+1});
            }
        }
    }
    return -1;
}

int main(){
    cin>>m>>n;
    mp.resize(m,vector<int>(n));
    aim_x=-1,aim_y=-1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mp[i][j];
            if(mp[i][j]==2){
                aim_x=i;
                aim_y=j;
            }
        }
    }
    int k;
    cin>>k;
    vector<pair<int,int>> teams(k);
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        teams[i]={y-1,x-1};
    }
    vector<int> times(k);
    map<int,int> s;
    for(int i=0;i<k;i++){
        times[i]=ss(teams[i].first,teams[i].second);
        s[times[i]]++;
    }
    int out=-1;
    for(auto [time,num]:s){
        if(num==1){
            out=time;
            break;
        }
    }
    if(out==-1){
        cout<<"No winner."<<endl;
        return 0;
    }
    for(int i=0;i<k;i++){
        if(times[i]==out){
            cout<<i+1<<" "<<out<<endl;
        }
    }
    return 0;
}
