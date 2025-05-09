#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long k;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> k;
    vector<vector<int>> pos(19);
    for (int i = 1; i <= n; i++) pos[a[i]].push_back(i);
    for (int x = 1; x <= 18; x++) pos[x].push_back(n+1);
    vector<int> idx(19, 0), cnt(19, 0);
    long long ans = 0;
    // r1 = 0 case
    {
        int e = n;
        for (int x = 1; x <= 18; x++) {
            long long rem = k - cnt[x];
            int t;
            if (rem < 0 || idx[x] + rem >= pos[x].size()) t = n;
            else t = pos[x][idx[x] + rem] - 1;
            e = min(e, t);
        }
        ans = max(ans, (long long)e);
    }
    int L = 1;
    for (int r = 1; r <= n; r++) {
        cnt[a[r]]++;
        while (cnt[a[r]] > k) {
            cnt[a[L]]--;
            L++;
        }
        for (int x = 1; x <= 18; x++) {
            while (idx[x] < pos[x].size() && pos[x][idx[x]] <= r) idx[x]++;
        }
        int e = n;
        for (int x = 1; x <= 18; x++) {
            long long rem = k - cnt[x];
            int t;
            if (rem < 0 || idx[x] + rem >= pos[x].size()) t = n;
            else t = pos[x][idx[x] + rem] - 1;
            e = min(e, t);
        }
        long long lenLeft = r - L + 1;
        ans = max(ans, lenLeft + (e - r));
    }
    cout << ans;
    return 0;
}