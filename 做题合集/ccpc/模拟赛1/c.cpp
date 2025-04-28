#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        vector<int> x(3), y(3);
        for (int i = 0; i < 3; ++i) cin >> x[i];
        for (int i = 0; i < 3; ++i) cin >> y[i];
        int sumY = y[0] + y[1] + y[2];
        int Rmax = sumY;
        vector<char> dp(Rmax+1, 0);
        dp[0] = 1;
        for (int i = 0; i < 3; ++i)
            for (int r = y[i]; r <= Rmax; ++r)
                if (dp[r - y[i]]) dp[r] = 1;
        int ans = -1;
        for (int S = 0; S <= 2 * sumY; ++S) {
            int sumri = 0;
            for (int i = 0; i < 3; ++i) {
                int ri = (S + x[i]) % y[i];
                sumri += ri;
            }
            int R = S - sumri;
            if (R < 0 || R > Rmax) continue;
            if (dp[R]) { ans = S; break; }
        }
        cout << ans << '\n';
    }
    return 0;
}