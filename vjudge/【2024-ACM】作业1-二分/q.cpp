#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-7;

int n, S, T;
vector<int> a;

// check函数判断是否存在平均值≥mid的段落
bool check(double mid) {
    // 计算前缀和：sum[i]表示前i个(原始值-mid)的累加和
    vector<double> sum(n + 1, 0.0);
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + (a[i - 1] - mid);
    }

    deque<int> dq; // 单调队列，存储可能的最小前缀和的索引
    for (int j = 1; j <= n; ++j) {
        // 如果当前位置j能形成长度至少为S的段落，则尝试将j-S加入队列
        int k_candidate = j - S;
        if (k_candidate >= 0) {
            // 维护单调性：移除队列尾部较大的元素
            while (!dq.empty() && sum[dq.back()] >= sum[k_candidate]) {
                dq.pop_back();
            }
            dq.push_back(k_candidate);
        }

        // 移除队列头部超出段落最大长度T的元素
        int current_left = j - T;
        while (!dq.empty() && dq.front() < current_left) {
            dq.pop_front();
        }

        // 检查是否找到满足条件的段落
        if (j >= S) { // 确保当前段落长度至少为S
            if (!dq.empty() && sum[j] - sum[dq.front()] >= 0) {
                return true; // 找到了平均值≥mid的段落
            }
        }
    }
    return false; // 未找到满足条件的段落
}

int main() {
    cin >> n >> S >> T;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    double left = *min_element(a.begin(), a.end());
    double right = *max_element(a.begin(), a.end());

    for (int iter = 0; iter < 100; ++iter) {
        double mid = (left + right) / 2;
        if (check(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    printf("%.3lf\n", left);
    return 0;
}
