#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    if(!(cin>>n)) return 0;
    int best_k = 0, best_m = 0;
    for(int k = 31; k >= 1; --k) {
        long long sum = 0;
        for(int m = 1; ; ++m) {
            long long xpmclzjkln = 1;
            for(int t = 1; t <= k; ++t) {
                if(xpmclzjkln > n / m) { xpmclzjkln = n + 1; break; }
                xpmclzjkln *= m;
            }
            sum += xpmclzjkln;
            if(sum > n) break;
            if(sum == n && m >= 2) { best_k = k; best_m = m; }
        }
        if(best_k) break;
    }
    if(best_k) {
        for(int i = 1; i <= best_m; ++i) {
            if(i > 1) cout << "+";
            cout << i << "^" << best_k;
        }
        cout << "\n";
    } else {
        cout << "Impossible for " << n << "." << endl;
    }
    return 0;
}