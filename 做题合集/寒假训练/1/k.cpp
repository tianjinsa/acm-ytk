#include<bits/stdc++.h>
using namespace std;

// 字符串大整数除法
string divide(string dividend, string divisor) {
    string result;
    string current;
    int idx = 0;
    
    while (idx < dividend.size()) {
        current += dividend[idx++];
        int quotient = 0;
        while (current.size() > 1 && current[0] == '0') {
            current.erase(0, 1);
        }
        while (current.size() >= divisor.size() && current >= divisor) {
            for (int i = 0; i < divisor.size(); ++i) {
                current[i] -= divisor[i] - '0';
                if (current[i] < '0') {
                    current[i] += 10;
                    current[i - 1]--;
                }
            }
            while (current.size() > 1 && current[0] == '0') {
                current.erase(0, 1);
            }
            quotient++;
        }
        result += (quotient + '0');
    }
    
    while (result.size() > 1 && result[0] == '0') {
        result.erase(0, 1);
    }
    
    return result.empty() ? "0" : result;
}

int main()
{
    string dividend, divisor;
    cin >> dividend >> divisor;
    
    // 计算商
    string quotient = divide(dividend, divisor);
    
    // 输出商
    cout << quotient << endl;
    
    return 0;
}