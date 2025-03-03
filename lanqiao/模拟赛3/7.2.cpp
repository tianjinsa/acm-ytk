#include<bits/stdc++.h>
using namespace std;

// 检查字符串是否满足条件：任意5个连续位置中不超过3个位置的值为1
bool check(const string& s) {
    for (int i = 0; i <= s.length() - 5; i++) {
        int count = 0;
        for (int j = i; j < i + 5; j++) {
            if (s[j] == '1') {
                count++;
            }
        }
        if (count > 3) {
            return false;
        }
    }
    return true;
}

// 递归生成所有可能的01串并计数
int generateAndCount(string current, int length, int target_length) {
    if (length == target_length) {
        return check(current) ? 1 : 0;
    }
    
    int count = 0;
    
    // 添加字符'0'
    count += generateAndCount(current + '0', length + 1, target_length);
    
    // 添加字符'1'
    count += generateAndCount(current + '1', length + 1, target_length);
    
    return count;
}

int main() {
    int result = generateAndCount("", 0, 24);
    cout << result << endl;
    return 0;
}