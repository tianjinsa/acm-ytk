#include<bits/stdc++.h>
using namespace std;
const int N = 105;
const int M = 5005;
int a[N][M];
int row_sum[N][M]; // 每行的前缀和
int col_sum[N][M]; // 每列的前缀和

int main()
{
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            // 计算行前缀和
            row_sum[i][j] = row_sum[i][j-1] + a[i][j];
        }
    }
    
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            // 计算列前缀和
            col_sum[i][j] = col_sum[i-1][j] + a[i][j];
        }
    }
    
    long long max_sum = LONG_LONG_MIN;
    
    // 枚举所有可能的十字形区域
    for (int r1 = 2; r1 < n; r1++) {
        for (int r2 = r1; r2 < n; r2++) {
            for (int c1 = 2; c1 < m; c1++) {
                for (int c2 = c1; c2 < m; c2++) {
                    // 计算十字形区域的和
                    long long sum = 0;
                    
                    // 计算行的和（从r1到r2的所有行）
                    for (int r = r1; r <= r2; r++) {
                        sum += row_sum[r][m];
                    }
                    
                    // 计算列的和（从c1到c2的所有列）
                    for (int c = c1; c <= c2; c++) {
                        sum += col_sum[n][c];
                    }
                    
                    // 减去重复计算的部分（行和列的交叉区域）
                    for (int r = r1; r <= r2; r++) {
                        for (int c = c1; c <= c2; c++) {
                            sum -= a[r][c];
                        }
                    }
                    
                    max_sum = max(max_sum, sum);
                }
            }
        }
    }
    
    cout << max_sum << endl;
    
    return 0;
}