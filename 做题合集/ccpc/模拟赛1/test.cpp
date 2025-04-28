#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    // 最优分配策略：让每种徽章分配尽量平均
    // 计算收集所有徽章的期望次数
    double expected = 0;
    
    // 计算调和级数 Hm = 1 + 1/2 + 1/3 + ... + 1/m
    for (int i = 1; i <= m; i++) {
        expected += (double)n / i;
    }
    
    cout << fixed << setprecision(10) << expected << endl;
    return 0;
}