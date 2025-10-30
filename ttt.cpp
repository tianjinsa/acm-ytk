#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 1000000 + 10; // 最大长度

ll fact[MAXN], invfact[MAXN];

ll modpow(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

void precompute_factorials() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = fact[i-1] * i % MOD;
    }
    invfact[MAXN-1] = modpow(fact[MAXN-1], MOD-2, MOD);
    for (int i = MAXN-2; i >= 0; --i) {
        invfact[i] = invfact[i+1] * (i+1) % MOD;
    }
}

ll C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}

// 计算长度为 L 的段，放 k 个不相邻1的方案数
ll ways(int L, int k) {
    if (k < 0 || k > (L+1)/2) return 0;
    return C(L - k + 1, k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute_factorials();

    string s;
    cin >> s;

    // 分割段：按 '2' 分割，记录每段连续 '0' 的长度
    vector<int> segs;
    int cur = 0;
    for (char c : s) {
        if (c == '0') {
            cur++;
        } else { // c == '2'
            if (cur > 0) {
                segs.push_back(cur);
                cur = 0;
            }
        }
    }
    if (cur > 0) segs.push_back(cur);

    // ans[k] = 放 k 个 1 的总方案数
    vector<ll> ans(1, 1); // 初始：0个1，1种方案

    for (int L : segs) {
        // 当前段的生成函数 poly: poly[k] = ways(L, k)
        vector<ll> poly;
        int maxk = (L + 1) / 2;
        for (int k = 0; k <= maxk; ++k) {
            poly.push_back(ways(L, k));
        }

        // 卷积：new_ans[i] = sum_{j=0}^{i} ans[j] * poly[i-j]
        vector<ll> new_ans(ans.size() + poly.size() - 1, 0);
        for (int i = 0; i < ans.size(); ++i) {
            for (int j = 0; j < poly.size(); ++j) {
                if (i + j < new_ans.size()) {
                    new_ans[i + j] = (new_ans[i + j] + ans[i] * poly[j]) % MOD;
                }
            }
        }
        ans = move(new_ans);
    }

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        if (x < ans.size()) {
            cout << ans[x] << '\n';
        } else {
            cout << 0 << '\n';
        }
    }

    return 0;
}