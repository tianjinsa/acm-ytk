#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
long long rval[MAXN];
long long seg[4*MAXN], lz[4*MAXN];

void pushdown(int p) {
    if (lz[p]) {
        seg[p<<1] += lz[p]; lz[p<<1] += lz[p];
        seg[p<<1|1] += lz[p]; lz[p<<1|1] += lz[p];
        lz[p] = 0;
    }
}

void build(int p, int l, int r) {
    if (l == r) seg[p] = rval[l];
    else {
        int m = (l + r) >> 1;
        build(p<<1, l, m);
        build(p<<1|1, m+1, r);
        seg[p] = min(seg[p<<1], seg[p<<1|1]);
    }
}

void update(int p, int l, int r, int ql, int qr, long long v) {
    if (ql > r || qr < l) return;
    if (ql <= l && r <= qr) {
        seg[p] += v;
        lz[p] += v;
        return;
    }
    pushdown(p);
    int m = (l + r) >> 1;
    update(p<<1, l, m, ql, qr, v);
    update(p<<1|1, m+1, r, ql, qr, v);
    seg[p] = min(seg[p<<1], seg[p<<1|1]);
}

long long query(int p, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return LLONG_MAX;
    if (ql <= l && r <= qr) return seg[p];
    pushdown(p);
    int m = (l + r) >> 1;
    return min(query(p<<1, l, m, ql, qr), query(p<<1|1, m+1, r, ql, qr));
}

int main()
{
    
    return 0;
}