#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int a = n / m;
    int r = n % m;
    int b = r;
    int s = m - r;
    double p_big = (a + 1) / (double)n;
    double p_small = a / (double)n;
    vector<double> dp(s + 2), dp_next(s + 2);
    for (int x = b; x >= 0; --x) {
        for (int y = s; y >= 0; --y) {
            if (x == b && y == s) dp[y] = 0.0;
            else {
                double pb = (b - x) * p_big;
                double ps = (s - y) * p_small;
                double p = pb + ps;
                double v = 1.0;
                if (x < b) v += pb * dp_next[y];
                if (y < s) v += ps * dp[y + 1];
                dp[y] = v / p;
            }
        }
        swap(dp, dp_next);
    }
    cout << fixed << setprecision(10) << dp_next[0];
    return 0;
}