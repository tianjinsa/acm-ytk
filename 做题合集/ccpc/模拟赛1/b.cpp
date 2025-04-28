#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;

// 珍珠的颜色序列
string s;
// 线段树，用于维护区间的翻转操作
int lazy[MAXN * 4];

// 更新区间[l, r]内的珍珠颜色
void update(int id, int l, int r, int ql, int qr) {
    // 如果该区间完全处于查询区间内
    if (ql <= l && r <= qr) {
        lazy[id] ^= 1;
        return;
    }
    
    int mid = (l + r) >> 1;
    // 更新左半区间
    if (ql <= mid) update(id << 1, l, mid, ql, qr);
    // 更新右半区间
    if (qr > mid) update(id << 1 | 1, mid + 1, r, ql, qr);
}

// 查询位置pos处珍珠的颜色
int query(int id, int l, int r, int pos) {
    // 计算从根节点到当前节点的lazy标记异或和
    if (l == r) return (s[l-1] - '0') ^ lazy[id];
    
    int mid = (l + r) >> 1;
    // 将lazy标记传递给子节点
    if (pos <= mid) return query(id << 1, l, mid, pos) ^ lazy[id];
    else return query(id << 1 | 1, mid + 1, r, pos) ^ lazy[id];
}

// 计算区间[l, r]内所需的最小取走次数
int solve(int n, int l, int r) {
    vector<int> colors;
    // 获取当前区间内所有珍珠的颜色
    for (int i = l; i <= r; i++) {
        colors.push_back(query(1, 1, n, i));
    }
    
    int count = 1; // 至少需要取一次
    // 计算颜色变化的次数
    for (int i = 1; i < colors.size(); i++) {
        if (colors[i] == colors[i-1]) {
            count++;
        }
    }
    
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    cin >> s;
    
    memset(lazy, 0, sizeof(lazy));
    
    for (int i = 0; i < q; i++) {
        char op;
        int l, r;
        cin >> op >> l >> r;
        
        if (op == 'M') {
            // 修改操作
            update(1, 1, n, l, r);
        } else {
            // 查询操作
            cout << solve(n, l, r) << "\n";
        }
    }
    
    return 0;
}