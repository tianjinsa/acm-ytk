#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
vector<int> g[N];  // 邻接表存储树
vector<vector<int>> balloons;  // 存储每个节点的气球类型
int n, q;

int bfs(int start) {
    vector<bool> vis(n + 1, false);
    queue<pair<int, int>> q;  // {节点, 距离}
    q.push({start, 0});
    vis[start] = true;
    
    unordered_map<int, int> cnt;  // 记录每种气球的数量
    // 先加入起始节点的气球
    for(int balloon : balloons[start]) {
        cnt[balloon]++;
        if(cnt[balloon] > 1) return 0;
    }
    
    while(!q.empty()) {
        int curr = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        for(int next : g[curr]) {
            if(!vis[next]) {
                vis[next] = true;
                // 加入新节点的气球
                for(int balloon : balloons[next]) {
                    cnt[balloon]++;
                    if(cnt[balloon] > 1) {
                        return dist + 1;
                    }
                }
                q.push({next, dist + 1});
            }
        }
    }
    return -1;  // 找不到重复气球
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> q;
    balloons.resize(n + 1);
    
    // 读入每个节点的气球信息
    for(int i = 1; i <= n; i++) {
        int ai;
        cin >> ai;
        balloons[i].resize(ai);
        for(int j = 0; j < ai; j++) {
            cin >> balloons[i][j];
        }
    }
    
    // 读入边的信息
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    // 处理询问
    while(q--) {
        int x;
        cin >> x;
        int res = bfs(x);
        if(res == -1) {
            cout << "IMPOSSIBLE!\n";
        } else {
            cout << res << "\n";
        }
    }
    
    return 0;
}
