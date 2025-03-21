#include<bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int dx[] = {-1, 0, 1, 0}; // 上、右、下、左四个方向的行偏移
const int dy[] = {0, 1, 0, -1}; // 上、右、下、左四个方向的列偏移

int n, m, T; // 地图尺寸和游戏时长
int grid[MAXN][MAXN]; // 原始地图，包括边界外的僵尸出发点
pair<int, int> camp; // 大本营位置

// 用于寻路的节点
struct PathNode {
    int x, y;
    int kill; // 被消灭的僵尸数量
    int step; // 步数
    vector<pair<int, int>> path;
    bool operator>(const PathNode& other) const {
        if (kill != other.kill) return kill > other.kill; // 优先选择消灭最少的路径
        return step > other.step; // 其次选择最短路径
    }
};

// 寻找僵尸的最优路径
vector<pair<int, int>> findBestPath(int startX, int startY) {
    priority_queue<PathNode, vector<PathNode>, greater<PathNode>> pq;
    vector<vector<pair<int, int>>> visited(MAXN, vector<pair<int, int>>(MAXN, {INT_MAX, INT_MAX}));
    
    pq.push({startX, startY, 0, 0, {{startX, startY}}});
    
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        
        int x = curr.x, y = curr.y;
        
        // 到达大本营
        if (grid[x][y] < 0) {
            return curr.path;
        }
        
        // 如果已有更好的路径
        if (curr.kill > visited[x][y].first || 
            (curr.kill == visited[x][y].first && curr.step >= visited[x][y].second)) {
            continue;
        }
        
        visited[x][y] = {curr.kill, curr.step};
        
        // 尝试四个方向移动
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 检查是否在地图内
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            
            int newKill = curr.kill;
            int newStep = curr.step + 1;
            
            // 如果有堡垒，计算消灭的僵尸数量
            if (grid[nx][ny] > 0) {
                newKill += grid[nx][ny];
            }
            
            // 如果新路径更优
            if (newKill < visited[nx][ny].first || 
                (newKill == visited[nx][ny].first && newStep < visited[nx][ny].second)) {
                vector<pair<int, int>> newPath = curr.path;
                newPath.push_back({nx, ny});
                pq.push({nx, ny, newKill, newStep, newPath});
            }
        }
    }
    
    // 如果没有找到路径
    return {};
}

// 僵尸队伍
struct ZombieTeam {
    int count;  // 僵尸数量
    int currentIndex;  // 当前在路径中的位置索引
    int arriveTime;  // 到达当前位置的时间
    vector<pair<int, int>> path;  // 路径
    
    ZombieTeam(int c, vector<pair<int, int>> p) 
        : count(c), currentIndex(1), arriveTime(1), path(p) {}
};

int main() {
    cin >> n >> m >> T;
    
    // 读取地图状态
    for (int i = 0; i <= n+1; ++i) {
        for (int j = 0; j <= m+1; ++j) {
            cin >> grid[i][j];
            if (1 <= i && i <= n && 1 <= j && j <= m && grid[i][j] < 0) {
                camp = {i, j};
            }
        }
    }
    
    // 收集所有僵尸队伍和计算其路径
    vector<ZombieTeam> zombies;
    for (int i = 0; i <= n+1; ++i) {
        for (int j = 0; j <= m+1; ++j) {
            if ((i == 0 || i == n+1 || j == 0 || j == m+1) && grid[i][j] > 0) {
                // 计算从该位置出发的僵尸的最优路径
                auto path = findBestPath(i, j);
                if (!path.empty()) {
                    zombies.emplace_back(grid[i][j], path);
                }
            }
        }
    }
    
    // 模拟游戏过程
    bool gameOver = false;
    int currentMap[MAXN][MAXN];
    memcpy(currentMap, grid, sizeof(grid));
    
    // 清除边界外的僵尸
    for (int i = 0; i <= n+1; ++i) {
        for (int j = 0; j <= m+1; ++j) {
            if (i == 0 || i == n+1 || j == 0 || j == m+1) {
                currentMap[i][j] = 0;
            }
        }
    }
    
    // 按时间模拟
    for (int t = 1; t <= T && !gameOver; ++t) {
        // 处理每队僵尸
        for (auto& zombie : zombies) {
            if (zombie.count <= 0) continue; // 这队僵尸已经被消灭
            
            // 检查是否应该移动/攻击
            if (t >= zombie.arriveTime) {
                int cx = zombie.path[zombie.currentIndex].first;
                int cy = zombie.path[zombie.currentIndex].second;
                
                if (currentMap[cx][cy] > 0) { // 堡垒
                    int defense = currentMap[cx][cy];
                    int killed = min(defense, zombie.count);
                    
                    currentMap[cx][cy] -= killed;
                    zombie.count -= killed;
                    
                    if (currentMap[cx][cy] <= 0) { // 堡垒被摧毁
                        currentMap[cx][cy] = 0;
                        if (zombie.count > 0) {
                            // 僵尸移动到这个位置
                            zombie.currentIndex++;
                            zombie.arriveTime = t + 1;
                        }
                    }
                } else if (currentMap[cx][cy] < 0) { // 大本营
                    int defense = -currentMap[cx][cy];
                    int killed = min(defense, zombie.count);
                    
                    defense -= killed;
                    zombie.count -= killed;
                    currentMap[cx][cy] = -defense;
                    
                    if (defense <= 0) { // 大本营被攻陷
                        gameOver = true;
                        break;
                    }
                } else { // 空地
                    // 继续前进
                    zombie.currentIndex++;
                    if (zombie.currentIndex < zombie.path.size()) {
                        zombie.arriveTime = t + 1;
                    }
                }
            }
        }
    }
    
    // 输出最终地图状态
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << (j > 1 ? " " : "") << currentMap[i][j];
        }
        cout << endl;
    }
    
    if (gameOver) {
        cout << "Game Over" << endl;
    }
    
    return 0;
}