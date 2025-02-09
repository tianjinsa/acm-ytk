#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int MOD = 1000000007;
 
// 快速求 a^b mod MOD
ll modexp(ll a, ll b) {
    ll res = 1;
    while(b){
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
 
// 求逆元
ll modinv(ll a) {
    return modexp(a, MOD-2);
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, q, k;
    cin >> n >> q >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    
    // 计算最小2的幂
    int size = 1;
    while(size < n) size *= 2;
    
    // 定义每个节点存储长度为 k 的多项式（下标 0~k-1）
    vector<vector<int>> seg(2*size, vector<int>(k, 0));
    // 单位元：多项式 = [1,0,...,0]
    vector<int> unit(k, 0); 
    unit[0] = 1;
    
    // 初始化叶节点
    for (int i=0; i<n; i++){
        ll s = modinv(a[i]); // 成功概率 = 1/a mod M
        ll fail = (1 - s) % MOD;
        if(fail < 0) fail += MOD;
        seg[size+i][0] = (int)fail;
        if(k > 1) seg[size+i][1] = (int)(s % MOD);
        // 其余项为 0
    }
    for (int i=n; i<size; i++){
        seg[size+i] = unit;
    }
 
    // 合并函数：给定多项式 L 与 R（下标 0~k-1），循环卷积合并到 C
    auto combine = [&](const vector<int>& L, const vector<int>& R) -> vector<int> {
        vector<int> C(k, 0);
        for (int r = 0; r < k; r++){
            ll sum = 0;
            for (int i = 0; i < k; i++){
                int j = (r - i) % k;
                if(j < 0) j += k;
                sum = (sum + (ll)L[i] * R[j]) % MOD;
            }
            C[r] = (int)sum;
        }
        return C;
    };
    
    // 建树：自底向上构造
    for (int i = size-1; i >= 1; i--){
        seg[i] = combine(seg[2*i], seg[2*i+1]);
    }
 
    // 迭代式查询区间 [l, r] (0-index)
    auto queryRange = [&](int l, int r) -> vector<int> {
        vector<int> leftRes = unit, rightRes = unit;
        l += size; r += size;
        while(l <= r){
            if(l & 1){
                leftRes = combine(leftRes, seg[l]);
                l++;
            }
            if(!(r & 1)){
                rightRes = combine(seg[r], rightRes);
                r--;
            }
            l >>= 1; r >>= 1;
        }
        return combine(leftRes, rightRes);
    };
 
    // 处理 q 次询问
    for (int i=0; i<q; i++){
        int L, R, p;
        cin >> L >> R >> p;
        // 转换为 0-index
        vector<int> poly = queryRange(L-1, R-1);
        cout << poly[p] % MOD << "\n";
    }
}
