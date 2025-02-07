#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

inline int count_pairs(const string& s, char first, char second) {
    int count = 0;
    for (int i = 0; i < (int)s.length() - 1; i++) {
        if (s[i] == first && s[i + 1] == second) count++;
    }
    return count;
}

bool is_balanced(const string& s) {
    return count_pairs(s, '0', '1') == count_pairs(s, '1', '0');
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<int> q_pos;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') q_pos.push_back(i);
    }
    
    int q_count = q_pos.size();
    long long ans = 0;
    
    // 枚举所有可能的?替换方案
    for (int mask = 0; mask < (1 << q_count); mask++) {
        string curr = s;
        // 将当前方案填入字符串
        for (int i = 0; i < q_count; i++) {
            curr[q_pos[i]] = ((mask >> i) & 1) ? '1' : '0';
        }
        
        // 检查每个位置翻转后是否平衡
        for (int i = 0; i < n; i++) {
            char original = curr[i];
            curr[i] = (original == '0') ? '1' : '0';
            
            if (is_balanced(curr)) {
                ans = (ans + 1) % MOD;
            }
            
            curr[i] = original;
        }
    }
    
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}