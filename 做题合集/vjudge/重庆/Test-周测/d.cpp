#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> A(n, vector<bool>(n, false));
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        u--; v--;
        A[u][v] = A[v][u] = true;
    }
    int N = n;
    int fullmask = (1 << N) - 1;
    vector<vector<bool>> B(N, vector<bool>(N, false));
    int minCost = INT_MAX;
    vector<pair<int,int>> curEdges;
    function<void(int)> rec = [&](int visited) {
        if (visited == fullmask) {
            int cost = 0;
            vector<vector<bool>> C(N, vector<bool>(N, false));
            for (auto &e : curEdges) C[e.first][e.second] = C[e.second][e.first] = true;
            for (int i = 0; i < N; i++)
                for (int j = i + 1; j < N; j++)
                    if (A[i][j] != C[i][j]) cost++;
            minCost = min(minCost, cost);
            return;
        }
        int u = 0;
        while (visited & (1 << u)) u++;
        vector<int> cand;
        for (int v = u + 1; v < N; v++) if (!(visited & (1 << v))) cand.push_back(v);
        int rem = __builtin_popcount(fullmask ^ visited);
        for (int k = 3; k <= rem; k++) {
            vector<int> comb;
            function<void(int,int)> gen = [&](int idx, int cnt) {
                if (cnt == k - 1) {
                    vector<int> perm = comb;
                    sort(perm.begin(), perm.end());
                    do {
                        if (perm.front() > perm.back()) continue;
                        int mask = 1 << u;
                        int last = u;
                        int prevSize = curEdges.size();
                        for (int x : perm) {
                            mask |= 1 << x;
                            curEdges.emplace_back(last, x);
                            last = x;
                        }
                        curEdges.emplace_back(last, u);
                        rec(visited | mask);
                        curEdges.resize(prevSize);
                    } while (next_permutation(perm.begin(), perm.end()));
                    return;
                }
                if (idx >= cand.size()) return;
                comb.push_back(cand[idx]);
                gen(idx + 1, cnt + 1);
                comb.pop_back();
                gen(idx + 1, cnt);
            };
            gen(0, 0);
        }
    };
    rec(0);
    cout << minCost;
    return 0;
}