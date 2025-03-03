#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> a(n+1, vector<int>(m+1));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    
    // 计算行的总和
    vector<long long> row_sum(n+1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            row_sum[i] += a[i][j];
        }
    }
    
    // 计算列的总和
    vector<long long> col_sum(m+1, 0);
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            col_sum[j] += a[i][j];
        }
    }
    
    long long max_sum = LONG_LONG_MIN;
    
    // 枚举行区间
    for (int r1 = 2; r1 < n; r1++) {
        for (int r2 = r1; r2 < n; r2++) {
            // 计算选定行的总和
            long long rows_total = 0;
            for (int r = r1; r <= r2; r++) {
                rows_total += row_sum[r];
            }
            
            // 枚举列区间
            for (int c1 = 2; c1 < m; c1++) {
                for (int c2 = c1; c2 < m; c2++) {
                    // 计算选定列的总和
                    long long cols_total = 0;
                    for (int c = c1; c <= c2; c++) {
                        cols_total += col_sum[c];
                    }
                    
                    // 计算重叠部分
                    long long overlap = 0;
                    for (int r = r1; r <= r2; r++) {
                        for (int c = c1; c <= c2; c++) {
                            overlap += a[r][c];
                        }
                    }
                    
                    // 十字形区域的和 = 行总和 + 列总和 - 重叠部分
                    long long sum = rows_total + cols_total - overlap;
                    max_sum = max(max_sum, sum);
                }
            }
        }
    }
    
    cout << max_sum << endl;
    
    return 0;
}
