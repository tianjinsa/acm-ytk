#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> xs(n), ys(n);
    long long Sx = 0, Sy = 0;
    for(int i = 0; i < n; ++i) {
        cin >> xs[i] >> ys[i];
        Sx += xs[i];
        Sy += ys[i];
    }
    vector<long long> d(n);
    for(int i = 0; i < n; ++i) {
        d[i] = Sy * xs[i] - Sx * ys[i];
    }
    vector<long long> pos, neg;
    for(long long v : d) {
        if(v > 0) pos.push_back(v);
        else if(v < 0) neg.push_back(v);
    }
    sort(pos.rbegin(), pos.rend());
    sort(neg.begin(), neg.end());
    long double ans = 0;
    __int128 sum = 0;
    for(int i = 0; i < (int)pos.size(); ++i) {
        sum += pos[i];
        int k = i + 1;
        if(k < n) {
            long double cur = (long double)sum / (2.0L * k * (n - k));
            if(cur > ans) ans = cur;
        }
    }
    sum = 0;
    for(int i = 0; i < (int)neg.size(); ++i) {
        sum += neg[i];
        int k = i + 1;
        if(k < n) {
            long double cur = -(long double)sum / (2.0L * k * (n - k));
            if(cur > ans) ans = cur;
        }
    }
    cout << fixed << setprecision(10) << ans << "\n";
    return 0;
}