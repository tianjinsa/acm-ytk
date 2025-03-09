#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
using namespace std;
 
struct Point {
    int x, y, r;
};
 
// 用于哈希 pair<int,int>
struct PairHash {
    size_t operator()(const pair<int,int>& p) const {
        return ((size_t)p.first << 20) ^ (size_t)p.second;
    }
};
 
// 判断是否为完美平方
bool isPerfectSquare(long long x, int &s) {
    if(x < 0) return false;
    s = (int)round(sqrt((long double)x));
    return (long long)s*s == x;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    vector<Point> pts(n);
    for (int i = 0; i < n; i++){
        cin >> pts[i].x >> pts[i].y >> pts[i].r;
    }
    // 构建哈希集合存储点（只存储坐标）
    unordered_set<pair<int,int>, PairHash> pointSet;
    for(auto &p: pts){
        pointSet.insert({p.x, p.y});
    }
 
    // 预计算：对于每个不同的 r (且 r<=282842，超出范围就肯定无邻点)，计算偏移量列表
    unordered_map<int, vector<pair<int,int>>> offsetCache;
    for(auto &p: pts){
        int r = p.r;
        // 点的坐标范围决定最大距离约为282842
        if(r > 282842) continue;
        if(offsetCache.count(r)) continue;
        vector<pair<int,int>> offsets;
        long long r2 = (long long)r * r;
        // 枚举 dx 从0到 r（dx 可能为0）
        for (int dx = 0; dx <= r; dx++){
            long long t = r2 - (long long)dx * dx;
            int dy;
            if(!isPerfectSquare(t, dy)) continue;
            // 注意：可能有重复，不同符号处理
            if(dx == 0 && dy == 0) continue; // 不会出现，也就忽略
            if(dx == 0 && dy != 0){
                offsets.push_back({0, dy});
                offsets.push_back({0, -dy});
            } else if(dy == 0 && dx != 0){
                offsets.push_back({dx,0});
                offsets.push_back({-dx,0});
            } else {
                offsets.push_back({dx,dy});
                offsets.push_back({dx,-dy});
                offsets.push_back({-dx,dy});
                offsets.push_back({-dx,-dy});
            }
        }
        offsetCache[r] = offsets;
    }
 
    // 统计总奇异度
    long long ans = 0;
    for(auto &p: pts){
        int r = p.r;
        // 超出点集中两点能达到的最大距离则直接跳过
        if(r > 282842) continue;
        const auto &offs = offsetCache[r];
        for(auto &d: offs){
            int nx = p.x + d.first, ny = p.y + d.second;
            if(pointSet.count({nx, ny})) ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
