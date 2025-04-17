#include<bits/stdc++.h>
using namespace std;

vector<int> num;  // 存储所有选手的能力值
set<int> st;      // 存储可用的能力值
int up = 0;       // 当前处理的位置指针

// 填充能力值函数
void inn(int &x) {
    // 如果没有可用的能力值，则无解
    if (up >= st.size()) {
        cout << "No Solution" << endl;
        exit(0);
    }
    // 从set中取出一个值
    auto it = next(st.begin(), up);
    int p = *it - 1;  // 获取对应的索引
    st.erase(it);     // 从可用集合中移除
    num[p] = x;       // 将能力值赋给对应选手
    up++;             // 更新指针
}

int main() {
    int k;
    cin >> k;
    int n = 1 << k;  // 计算选手总数 2^k
    
    // 初始化选手编号和可用能力值集合
    num.resize(n);
    for (int i = 1; i <= n; i++) {
        num[i-1] = i;  // 选手编号从1开始
        st.insert(i);   // 初始可用能力值集合
    }
    
    // 从后往前处理每轮比赛
    for (int i = k; i >= 1; i--) {
        for (int j = 0; j < (1 << (i - 1)); j++) {
            int x;
            cin >> x;    // 读取败者能力值
            inn(x);      // 填充败者能力值
        }
        up = 0;  // 重置指针，准备下一轮
    }
    
    // 读取并填充最终胜者的能力值
    int winner;
    cin >> winner;
    inn(winner);
    
    // 输出所有选手的能力值
    bool first = true;
    for (auto& x : num) {
        if (!first) cout << ' ';
        first = false;
        cout << x;
    }
    
    return 0;
}