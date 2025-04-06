#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    // 用来存储性别信息，true为男性，false为女性
    vector<bool> gender(n);
    
    // 用于存储亲密度
    vector<vector<double>> intimacy(n, vector<double>(n, 0.0));
    
    // 读取照片信息并计算亲密度
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        vector<int> people(k);
        for (int j = 0; j < k; j++) {
            cin >> people[j];
            // 记录性别（负数为女性）
            if (people[j] < 0) {
                people[j] = -people[j];  // 转为正数以便索引
                gender[people[j]] = false;
            } else {
                gender[people[j]] = true;
            }
        }
        
        // 计算照片中每对人的亲密度
        double value = 1.0 / k;
        for (int j = 0; j < k; j++) {
            for (int l = j + 1; l < k; l++) {
                intimacy[people[j]][people[l]] += value;
                intimacy[people[l]][people[j]] += value;
            }
        }
    }
    
    // 读取情侣信息
    int a, b;
    cin >> a >> b;
    
    // 确保a和b是正索引
    bool aGender = a > 0;
    bool bGender = b > 0;
    if (a < 0) {
        a = -a;
        aGender = false;
    } else {
        aGender = true;
    }
    if (b < 0) {
        b = -b;
        bGender = false;
    } else {
        bGender = true;
    }
    
    // 找出与A亲密度最高的异性
    vector<int> aHighest;
    double maxIntimacyA = -1;
    for (int i = 0; i < n; i++) {
        if (gender[i] != aGender && intimacy[a][i] > maxIntimacyA) {
            maxIntimacyA = intimacy[a][i];
            aHighest.clear();
            aHighest.push_back(i);
        } else if (gender[i] != aGender && intimacy[a][i] == maxIntimacyA) {
            aHighest.push_back(i);
        }
    }
    
    // 找出与B亲密度最高的异性
    vector<int> bHighest;
    double maxIntimacyB = -1;
    for (int i = 0; i < n; i++) {
        if (gender[i] != bGender && intimacy[b][i] > maxIntimacyB) {
            maxIntimacyB = intimacy[b][i];
            bHighest.clear();
            bHighest.push_back(i);
        } else if (gender[i] != bGender && intimacy[b][i] == maxIntimacyB) {
            bHighest.push_back(i);
        }
    }
    
    // 检查A和B是否互为对方最亲密的异性
    bool aInB = find(bHighest.begin(), bHighest.end(), a) != bHighest.end();
    bool bInA = find(aHighest.begin(), aHighest.end(), b) != aHighest.end();
    
    if (aInB && bInA && aHighest.size() == 1 && bHighest.size() == 1) {
        // A和B互为对方最亲密的异性
        cout << (aGender ? a : -a) << " " << (bGender ? b : -b) << endl;
    } else {
        // 输出A最亲密的异性
        cout << (aGender ? a : -a) << " ";
        for (size_t i = 0; i < aHighest.size(); i++) {
            cout << (gender[aHighest[i]] ? aHighest[i] : -aHighest[i]);
            if (i < aHighest.size() - 1) cout << " ";
        }
        cout << endl;
        
        // 输出B最亲密的异性
        cout << (bGender ? b : -b) << " ";
        for (size_t i = 0; i < bHighest.size(); i++) {
            cout << (gender[bHighest[i]] ? bHighest[i] : -bHighest[i]);
            if (i < bHighest.size() - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}