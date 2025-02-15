#include <bits/stdc++.h>
using namespace std;

// 定义树状数组（BIT）
struct BIT {
    int n;
    vector<int> tree;
    BIT(int n): n(n), tree(n+1,0) {}
    void update(int i, int delta) {
        for(; i <= n; i += i & -i)
            tree[i] += delta;
    }
    int query(int i) {
        int s = 0;
        for(; i > 0; i -= i & -i)
            s += tree[i];
        return s;
    }
};

struct Query {
    int l, r, c, id, threshold;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        vector<int> p(n);
        for (int i = 0; i < n; i++){
            cin >> p[i];
        }
        vector<Query> qs(m);
        for (int i = 0; i < m; i++){
            int l, r, c;
            cin >> l >> r >> c;
            qs[i] = {l, r, c, i, p[c-1]};
        }

        // 排序：先对 p 数组构造 (val, pos) 数组
        vector<pair<int,int>> arr(n); // (val, pos)
        for(int i=0;i<n;i++){
            arr[i] = {p[i], i};
        }
        sort(arr.begin(), arr.end());

        // 按 threshold 升序排序查询
        sort(qs.begin(), qs.end(), [](const Query& a, const Query& b){
            return a.threshold < b.threshold;
        });

        BIT bit(n);
        vector<int> ans(m);
        int idx = 0;
        // 对于每个查询，更新 BIT 中所有值小于 threshold 的位置
        for(auto &q : qs){
            while(idx < n && arr[idx].first < q.threshold){
                // BIT下标从1开始，arr[idx].second为下标0-based
                bit.update(arr[idx].second + 1, 1);
                idx++;
            }
            int count = bit.query(q.r) - bit.query(q.l - 1);
            ans[q.id] = q.l + count;
        }

        // 输出答案
        for(auto a : ans)
            cout << a << "\n";
    }
    return 0;
}