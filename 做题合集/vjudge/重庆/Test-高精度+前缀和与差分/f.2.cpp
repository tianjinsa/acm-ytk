#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
    int n;
    vector<ll> mn, lz;
    SegTree(int _n, vector<ll>& a): n(_n) {
        mn.resize(4*n);
        lz.assign(4*n, 0);
        build(1, 1, n, a);
    }
    void build(int p, int l, int r, vector<ll>& a) {
        if (l == r) {
            mn[p] = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build(p<<1, l, m, a);
        build(p<<1|1, m+1, r, a);
        mn[p] = min(mn[p<<1], mn[p<<1|1]);
    }
    void push(int p) {
        if (lz[p]) {
            ll v = lz[p];
            mn[p<<1] -= v; lz[p<<1] += v;
            mn[p<<1|1] -= v; lz[p<<1|1] += v;
            lz[p] = 0;
        }
    }
    ll query_min(int p, int l, int r, int i, int j) {
        if (r < i || l > j) return LLONG_MAX;
        if (l >= i && r <= j) return mn[p];
        push(p);
        int m = (l + r) >> 1;
        return min(query_min(p<<1, l, m, i, j), query_min(p<<1|1, m+1, r, i, j));
    }
    void update(int p, int l, int r, int i, int j, ll v) {
        if (r < i || l > j) return;
        if (l >= i && r <= j) {
            mn[p] -= v;
            lz[p] += v;
            return;
        }
        push(p);
        int m = (l + r) >> 1;
        update(p<<1, l, m, i, j, v);
        update(p<<1|1, m+1, r, i, j, v);
        mn[p] = min(mn[p<<1], mn[p<<1|1]);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<ll> r(n+1);
    for (int i = 1; i <= n; i++) cin >> r[i];
    SegTree st(n, r);
    for (int j = 1; j <= m; j++) {
        ll d; int s, t;
        cin >> d >> s >> t;
        if (st.query_min(1, 1, n, s, t) < d) {
            cout << -1 << "\n" << j;
            return 0;
        }
        st.update(1, 1, n, s, t, d);
    }
    cout << 0;
    return 0;
}