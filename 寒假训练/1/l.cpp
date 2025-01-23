#include<bits/stdc++.h>
using namespace std;

int main()
{
    // 读取两个浮点数
    string num1, num2;
    cin >> num1 >> num2;

    // 找到小数点位置
    size_t pos1 = num1.find('.');
    size_t pos2 = num2.find('.');

    // 分离整数部分和小数部分
    string intPart1 = num1.substr(0, pos1);
    string fracPart1 = num1.substr(pos1 + 1);
    string intPart2 = num2.substr(0, pos2);
    string fracPart2 = num2.substr(pos2 + 1);

    // 处理小数部分
    while (fracPart1.length() < fracPart2.length()) fracPart1 += '0';
    while (fracPart2.length() < fracPart1.length()) fracPart2 += '0';

    // 处理整数部分
    reverse(intPart1.begin(), intPart1.end());
    reverse(intPart2.begin(), intPart2.end());

    // 相加小数部分
    string fracSum;
    int carry = 0;
    for (int i = fracPart1.length() - 1; i >= 0; --i) {
        int sum = (fracPart1[i] - '0') + (fracPart2[i] - '0') + carry;
        carry = sum / 10;
        fracSum += (sum % 10) + '0';
    }
    reverse(fracSum.begin(), fracSum.end());

    // 相加整数部分
    string intSum;
    for (int i = 0; i < max(intPart1.length(), intPart2.length()); ++i) {
        int digit1 = i < intPart1.length() ? intPart1[i] - '0' : 0;
        int digit2 = i < intPart2.length() ? intPart2[i] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        intSum += (sum % 10) + '0';
    }
    if (carry) intSum += carry + '0';
    reverse(intSum.begin(), intSum.end());

    // 输出结果
    cout << intSum << "." << fracSum << endl;

    return 0;
}