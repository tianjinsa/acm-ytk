#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
long long qmi(int x,int a,int modx) {
    long long res = 1;
    while(a) {
        if(a & 1) res = res * x % modx;
        x = x * x % modx;
        a >>= 1;
    }
    return res;
}
int main()
{
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    int m = s.size();
    vector<int> pi(m);
    for (int i = 1; i < m; i++) {
        int j = pi[i-1];
        while (j && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    vector<array<int,26>> go(m);
    for (int i = 0; i < m; i++) {
        for (int c = 0; c < 26; c++) {
            char ch = 'a' + c;
            if (i && ch != s[i]) go[i][c] = go[pi[i-1]][c];
            else go[i][c] = (ch == s[i] ? i+1 : 0);
        }
    }
    const int MOD = 998244353;
    vector<vector<int>> dp(m, vector<int>(k+1));
    dp[0][0] = 1;
    for (int pos = 0; pos < n; pos++) {
        vector<vector<int>> ndp(m, vector<int>(k+1));
        for (int st = 0; st < m; st++) for (int t = 0; t <= k; t++) if (dp[st][t]) {
            int val = dp[st][t];
            for (int c = 0; c < 26; c++) {
                int v = go[st][c];
                if (v == m) {
                    if (t+1 <= k) {
                        ndp[0][t+1] = (ndp[0][t+1] + val) % MOD;
                    }
                } else {
                    ndp[v][t] = (ndp[v][t] + val) % MOD;
                }
            }
        }
        dp.swap(ndp);
    }
    int ans = 0;
    for (int st = 0; st < m; st++) ans = (ans + dp[st][k]) % MOD;
    cout << ans;
    return 0;
}