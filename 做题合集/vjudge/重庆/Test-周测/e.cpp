#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long L, R;
    cin >> L >> R;
    if (L == R) {
        cout << 1 << "\n";
        return 0;
    }
    long long len = R - L + 1;
    vector<char> isPrimeSegment(len, true);
    long long sqrtR = sqrtl(R);
    vector<int> primes;
    vector<char> isPrimeSmall(sqrtR + 1, true);
    isPrimeSmall[0] = isPrimeSmall[1] = false;
    for (int i = 2; i <= sqrtR; ++i) {
        if (isPrimeSmall[i]) {
            for (long long j = 1LL * i * i; j <= sqrtR; j += i) {
                isPrimeSmall[j] = false;
            }
            primes.push_back(i);
        }
    }
    for (int p : primes) {
        long long start = max(1LL * p * p, ((L + p - 1) / p) * p);
        for (long long j = start; j <= R; j += p) {
            isPrimeSegment[j - L] = false;
        }
    }
    if (L == 1) isPrimeSegment[0] = false;
    long long cnt = 0;
    for (long long i = 0; i < len; ++i) {
        if (isPrimeSegment[i]) cnt++;
    }
    // count higher prime powers
    for (int p : primes) {
        __int128 v = (__int128)p * p;
        while (v <= R) {
            if (v > L) cnt++;
            v *= p;
        }
    }
    cout << cnt + 1 << "\n";

    return 0;
}