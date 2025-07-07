#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long L;
    int Q;
    cin >> L >> Q;
    set<long long> cuts;
    cuts.insert(0);
    cuts.insert(L);
    for (int i = 0; i < Q; ++i) {
        int c;
        long long x;
        cin >> c >> x;
        if (c == 1) {
            cuts.insert(x);
        } else {
            auto it = cuts.upper_bound(x);
            long long r = *it;
            --it;
            long long l = *it;
            cout << (r - l) << "\n";
        }
    }
    
    return 0;
}