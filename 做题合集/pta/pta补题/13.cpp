#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int N;

void dfs(int start, const vector<bool>& lost) {
    stack<int> s;
    s.push(start);
    visited[start] = true;

    while (!s.empty()) {
        int u = s.top();
        s.pop();

        for (int v : adj[u]) {
            if (!lost[v] && !visited[v]) {
                visited[v] = true;
                s.push(v);
            }
        }
    }
}

int get(const vector<bool>& lost) {
    visited.assign(N, false);
    int components = 0;
    for (int i = 0; i < N; ++i) {
        if (!lost[i] && !visited[i]) {
            dfs(i, lost);
            components++;
        }
    }
    return components;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int M;
    cin >> N >> M;

    adj.resize(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int K,t1,t2;
    cin >> K;


    vector<bool> lost(N, false);
    int cont = N;
    t1 = get(lost);
    for (int i = 0; i < K; ++i) {
        int city;
        cin >> city;
        lost[city] = true;
        cont--;
        if (cont == 0) {
            cout << "City " << city << " is lost.\n";
            cout << "Game Over.\n";
            break;
        }
        t2 = get(lost);
        if (t2 > t1) {
            cout << "Red Alert: City " << city << " is lost!\n";
        } else {
            cout << "City " << city << " is lost.\n";
        }
        t1 = t2;
    }

    return 0;
}