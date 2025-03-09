#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <unordered_set>
#include <climits>

using namespace std;

struct Pear {
    int A, B;
};

int main() {
    int N;
    cin >> N;
    int C1, C2, C3;
    cin >> C1 >> C2 >> C3;
    vector<Pear> pears(N);
    for (int i = 0; i < N; ++i) {
        cin >> pears[i].A >> pears[i].B;
    }

    // Collect all unique A values as candidates for A0
    vector<int> a_candidates;
    for (const auto& p : pears) {
        a_candidates.push_back(p.A);
    }
    sort(a_candidates.begin(), a_candidates.end());
    a_candidates.erase(unique(a_candidates.begin(), a_candidates.end()), a_candidates.end());

    int max_count = 0;

    for (int a0 : a_candidates) {
        vector<Pear> s_collection;
        for (const auto& p : pears) {
            if (p.A >= a0) {
                int delta_A = p.A - a0;
                if (C1 * delta_A > C3) {
                    continue;
                }
                s_collection.push_back(p);
            }
        }

        if (s_collection.empty()) {
            continue;
        }

        vector<pair<int, int>> events;
        for (const auto& p : s_collection) {
            int delta_A = p.A - a0;
            int numerator = C3 - C1 * delta_A;
            int t_i = numerator / C2;
            int L_i = p.B - t_i;
            int R_i = p.B;
            events.emplace_back(L_i, 1);
            events.emplace_back(R_i + 1, -1);
        }

        sort(events.begin(), events.end());

        vector<tuple<int, int, int>> intervals;
        int current_count = 0;
        int prev_x = INT_MIN;

        for (const auto& event : events) {
            int x = event.first;
            int delta = event.second;
            if (x != prev_x) {
                if (prev_x != INT_MIN) {
                    intervals.emplace_back(prev_x, x, current_count);
                }
                prev_x = x;
            }
            current_count += delta;
        }
        if (prev_x != INT_MIN && !events.empty()) {
            intervals.emplace_back(prev_x, events.back().first + 1, current_count);
        }

        unordered_set<int> b_candidates_set;
        for (const auto& p : s_collection) {
            b_candidates_set.insert(p.B);
        }
        vector<int> b_list(b_candidates_set.begin(), b_candidates_set.end());
        sort(b_list.begin(), b_list.end());

        int current_max = 0;
        for (int b0 : b_list) {
            int left = 0, right = intervals.size();
            while (left < right) {
                int mid = (left + right) / 2;
                if (get<0>(intervals[mid]) > b0) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            int idx = right - 1;
            int count = 0;
            if (idx >= 0 && idx < (int)intervals.size()) {
                if (get<0>(intervals[idx]) <= b0 && b0 < get<1>(intervals[idx])) {
                    count = get<2>(intervals[idx]);
                }
            }
            if (count > current_max) {
                current_max = count;
            }
        }

        if (current_max > max_count) {
            max_count = current_max;
        }
    }

    cout << max_count << endl;

    return 0;
}
