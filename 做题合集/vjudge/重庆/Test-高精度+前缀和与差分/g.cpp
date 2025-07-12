#include <bits/stdc++.h>
using namespace std;
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void toggle_element_in_sorted_vector(vector<int>& vec, int val) {
    auto it = lower_bound(vec.begin(), vec.end(), val);
    if (it != vec.end() && *it == val) {
        vec.erase(it); 
    } else {
        vec.insert(it, val); 
    }
}

int main() {
    fast_io(); 

    int n, k, m;
    cin >> n >> k >> m; 
    set<int> initial_dark_lights_set; 
    for (int i = 0; i < k; ++i) {
        int pos;
        cin >> pos;
        initial_dark_lights_set.insert(pos);
    }
    vector<int> b_lengths(m); 
    for (int i = 0; i < m; ++i) {
        cin >> b_lengths[i];
    }
    vector<int> initial_diff_points; 
    bool prev_is_dark = false; 
    for (int i = 1; i <= n; ++i) {
        bool current_is_dark = initial_dark_lights_set.count(i); 
        if (current_is_dark != prev_is_dark) {
            initial_diff_points.push_back(i); 
        }
        prev_is_dark = current_is_dark; 
    }
    if (prev_is_dark) { 
        initial_diff_points.push_back(n + 1);
    }
    queue<vector<int>> q; 
    map<vector<int>, int> dist; 
    q.push(initial_diff_points); 
    dist[initial_diff_points] = 0; 
    
    int min_ops = -1; 
    while (!q.empty()) {
        vector<int> current_diff = q.front(); 
        q.pop(); 
        int current_steps = dist[current_diff]; 
        if (current_diff.empty()) {
            min_ops = current_steps;
            break; 
        }
        for (int p : current_diff) {
            for (int len : b_lengths) {
                int L1 = p;
                int R1_plus_1 = p + len;
                if (R1_plus_1 <= n + 1) { 
                    vector<int> next_diff = current_diff; 
                    toggle_element_in_sorted_vector(next_diff, L1);
                    toggle_element_in_sorted_vector(next_diff, R1_plus_1);
                    if (dist.find(next_diff) == dist.end()) {
                        dist[next_diff] = current_steps + 1; 
                        q.push(next_diff); 
                    }
                }
                int R2_plus_1 = p;
                int L2 = p - len;
                if (L2 >= 1) { 
                    vector<int> next_diff = current_diff; 
                    toggle_element_in_sorted_vector(next_diff, L2);
                    toggle_element_in_sorted_vector(next_diff, R2_plus_1);
                    if (dist.find(next_diff) == dist.end()) {
                        dist[next_diff] = current_steps + 1; 
                        q.push(next_diff); 
                    }
                }
            }
        }
    }

    cout << min_ops << endl; 

    return 0;
}

