#include <iostream>
using namespace std;

int main() {
    int count_ones[16];
    for (int s = 0; s < 16; ++s) {
        int cnt = 0;
        int temp = s;
        while (temp) {
            cnt += temp & 1;
            temp >>= 1;
        }
        count_ones[s] = cnt;
    }

    long long dp_prev[16];
    for (int i = 0; i < 16; ++i) {
        dp_prev[i] = 1;
    }

    for (int k = 5; k <= 24; ++k) {
        long long dp_current[16] = {0};

        for (int s_prev = 0; s_prev < 16; ++s_prev) {
            int cnt = count_ones[s_prev];

            // 添加0
            if (cnt <= 3) {
                int s_new = (s_prev << 1) & 0x0F;
                dp_current[s_new] += dp_prev[s_prev];
            }

            // 添加1
            if (cnt + 1 <= 3) {
                int s_new = (s_prev << 1 | 1) & 0x0F;
                dp_current[s_new] += dp_prev[s_prev];
            }
        }

        for (int i = 0; i < 16; ++i) {
            dp_prev[i] = dp_current[i];
        }
    }

    long long result = 0;
    for (int i = 0; i < 16; ++i) {
        result += dp_prev[i];
    }

    cout << result << endl;

    return 0;
}
