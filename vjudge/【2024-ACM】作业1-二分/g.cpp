#include<bits/stdc++.h>
using namespace std;

// 计算给定利率下的每月还款金额
double calculatePayment(double principal, double rate, int months) {
    if (fabs(rate) < 1e-10) {
        return principal / months;
    }
    return principal * rate * pow(1 + rate, months) / (pow(1 + rate, months) - 1);
}

int main()
{
    double w0, w; // w0为贷款金额，w为每月还款金额
    int m; // m为还款月数
    cin >> w0 >> w >> m;
    
    // 二分查找月利率（0%到300%）
    double left = 0, right = 3.0;
    const double eps = 1e-10;
    
    // 二分查找过程
    for (int i = 0; i < 100; i++) { // 迭代次数足够多以保证精度
        double mid = (left + right) / 2;
        double payment = calculatePayment(w0, mid, m);
        
        if (fabs(payment - w) < eps) {
            left = right = mid; // 找到精确解
            break;
        } else if (payment > w) {
            right = mid;
        } else {
            left = mid;
        }
    }
    
    // 转换为百分数并四舍五入到0.1%
    double result = left * 100;
    result = round(result * 10) / 10;
    
    // 输出结果
    cout << fixed << setprecision(1) << result << "%" << endl;
    
    return 0;
}