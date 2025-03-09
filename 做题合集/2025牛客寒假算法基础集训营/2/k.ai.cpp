#include<bits/stdc++.h>
using namespace std;
char a[500+2][500+2]={0};
unordered_set<int> mp;
void sss(const int x, const int y){
    // 使用显式栈代替递归
    stack<pair<int, int>> stk;
    stk.emplace(x, y);
    while(!stk.empty()){
        auto [cx, cy] = stk.top();
        stk.pop();
        if(a[cx][cy] != '1') continue;
        a[cx][cy] = 0;
        // 上下左右四个方向
        vector<pair<int, int>> directions = {{cx+1, cy}, {cx-1, cy}, {cx, cy+1}, {cx, cy-1}};
        for(auto &[nx, ny] : directions){
            if(a[nx][ny] == '1' && mp.find(nx * 505 + ny) == mp.end()){
                stk.emplace(nx, ny);
            } else if(a[nx][ny] == '0'){
                mp.emplace(nx * 505 + ny);
            }
        }
    }
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