#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    vector<long long> A;
    bool sorted = true;
    for (int i = 0; i < Q; i++) {
        int c;
        cin >> c;
        if (c == 1) {
            long long x;
            cin >> x;
            A.push_back(x);
            sorted = false;
        } else if (c == 2) {
            cout << A.front() << '\n';
            A.erase(A.begin());
        } else if (c == 3) {
            if (!sorted) {
                sort(A.begin(), A.end());
                sorted = true;
            }
        }
    }
    return 0;
}