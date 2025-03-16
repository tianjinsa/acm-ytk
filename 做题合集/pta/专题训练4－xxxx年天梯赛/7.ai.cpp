#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 记录情侣关系
    unordered_map<int, int> couples;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int id1, id2;
        cin >> id1 >> id2;
        couples[id1] = id2;
        couples[id2] = id1;
    }

    // 读取派对座位安排
    int m;
    cin >> m;
    vector<int> seats(m);
    for (int i = 0; i < m; i++) {
        cin >> seats[i];
    }

    // 计算单身人士被撒的狗粮数量
    unordered_map<int, int> dogFood;
    
    // 情况1: 情侣坐在一起，身边的单身狗被撒狗粮
    for (int i = 0; i < m - 1; i++) {
        if (couples.count(seats[i]) && couples[seats[i]] == seats[i + 1]) {
            // 左边的单身狗
            if (i > 0 && !couples.count(seats[i - 1])) {
                dogFood[seats[i - 1]]++;
            }
            // 右边的单身狗
            if (i + 2 < m && !couples.count(seats[i + 2])) {
                dogFood[seats[i + 2]]++;
            }
        }
    }

    // 情况2: 情侣没坐在一起，中间的单身狗被撒狗粮
    for (int i = 0; i < m; i++) {
        if (couples.count(seats[i])) {
            int partner = couples[seats[i]];
            // 找另一半在座位中的位置
            for (int j = i + 1; j < m; j++) {
                if (seats[j] == partner) {
                    // 统计中间的单身狗
                    for (int k = i + 1; k < j; k++) {
                        if (!couples.count(seats[k])) {
                            dogFood[seats[k]]++;
                        }
                    }
                    break;
                }
            }
        }
    }

    // 找出被撒狗粮最多的单身狗
    int maxFood = 0;
    for (const auto& p : dogFood) {
        maxFood = max(maxFood, p.second);
    }

    // 按ID递增顺序排列输出
    vector<int> result;
    for (const auto& p : dogFood) {
        if (p.second == maxFood) {
            result.push_back(p.first);
        }
    }
    sort(result.begin(), result.end());

    // 输出结果
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
