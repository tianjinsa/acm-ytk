#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> P(n), Q(n), posP(n+1), posQ(n+1), arr(n);
    for(int i = 0; i < n; i++) cin >> P[i];
    for(int i = 0; i < n; i++) cin >> Q[i];
    for(int i = 0; i < n; i++) {
        posP[P[i]] = i;
        posQ[Q[i]] = i;
    }
    for(int v = 1; v <= n; v++) {
        arr[posP[v]] = posQ[v];
    }
    set<int> S;
    long long ans = 0;
    int R = 1;
    int nValues = n;
    long long breakCnt = 0;
    auto isBreak = [&](int u, int v){ return arr[u] > arr[v]; };
    for(int L = 1; L <= nValues; L++) {
        while(R <= nValues) {
            int p = posP[R];
            auto it = S.lower_bound(p);
            int prev = -1, next = -1;
            if(it != S.end()) next = *it;
            if(it != S.begin()) { auto it2 = it; --it2; prev = *it2; }
            long long tmp = breakCnt;
            if(prev != -1 && next != -1) tmp -= isBreak(prev, next);
            if(prev != -1) tmp += isBreak(prev, p);
            if(next != -1) tmp += isBreak(p, next);
            if(tmp == 0) {
                breakCnt = tmp;
                S.insert(p);
                R++;
            } else break;
        }
        ans += (R - L);
        int rem = posP[L];
        auto it = S.find(rem);
        int prev = -1, next = -1;
        if(it != S.end()) {
            auto itn = it; ++itn;
            if(itn != S.end()) next = *itn;
            if(it != S.begin()) { auto itp = it; --itp; prev = *itp; }
            if(prev != -1) breakCnt -= isBreak(prev, rem);
            if(next != -1) breakCnt -= isBreak(rem, next);
            if(prev != -1 && next != -1) breakCnt += isBreak(prev, next);
            S.erase(it);
        }
    }
    cout << ans;
    return 0;
}