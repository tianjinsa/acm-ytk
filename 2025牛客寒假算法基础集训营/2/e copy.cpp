#include<bits/stdc++.h>
using namespace std;

// struct Node 用于同时存储当前区间的调整次数与倒下后总重量
struct Node {
    long long increments, totalWeight;
} seg[800000]; // 视 n 大小适当开辟

void build(int idx, int l, int r, const vector<int> &a) {
    if (l == r) {
        seg[idx].increments = 0;
        seg[idx].totalWeight = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(idx * 2, l, mid, a);
    build(idx * 2 + 1, mid + 1, r, a);
    seg[idx] = mergeNode(seg[idx * 2], seg[idx * 2 + 1]);
}

Node mergeNode(const Node &L, const Node &R) {
    Node ret;
    ret.totalWeight = L.totalWeight + R.totalWeight;
    if (L.totalWeight < R.totalWeight) {
        ret.increments = L.increments + R.increments + (R.totalWeight - L.totalWeight);
    } else {
        ret.increments = L.increments + R.increments;
    }
    return ret;
}

Node query(int idx, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return seg[idx];
    }
    int mid = (l + r) / 2;
    if (qr <= mid) {
        return query(idx * 2, l, mid, ql, qr);
    }
    if (ql > mid) {
        return query(idx * 2 + 1, mid + 1, r, ql, qr);
    }
    return mergeNode(query(idx * 2, l, mid, ql, qr), query(idx * 2 + 1, mid + 1, r, ql, qr));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    // 构建线段树
    build(1, 0, n-1, a);
    while(q--){
        int l,r;
        cin >> l >> r;
        // 调用线段树查询区间 [l-1, r-1]
        Node ans = query(1, 0, n-1, l-1, r-1);
        cout << ans.increments << "\n";
    }
    return 0;
}