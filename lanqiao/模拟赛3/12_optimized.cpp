#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> a(n+1, vector<int>(m+1));
    
    // 读取矩阵
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    
    // 计算行的前缀和
    vector<vector<long long>> row_prefix(n+1, vector<long long>(m+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            row_prefix[i][j] = row_prefix[i][j-1] + a[i][j];
        }
    }
    
    // 计算列的前缀和
    vector<vector<long long>> col_prefix(n+1, vector<long long>(m+1, 0));
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            col_prefix[i][j] = col_prefix[i-1][j] + a[i][j];
        }
    }
    
    long long max_sum = LONG_LONG_MIN;
    
    // 优化：首先枚举行区间
    for (int r1 = 2; r1 < n; r1++) {
        for (int r2 = r1; r2 < n; r2++) {
            // 计算这个行区间的每一列的贡献
            vector<long long> col_contribution(m+1, 0);
            
            // 计算行区间的贡献
            long long row_total = 0;
            for (int r = r1; r <= r2; r++) {
                row_total += row_prefix[r][m];
            }
            
            // 枚举列区间
            for (int c1 = 2; c1 < m; c1++) {
                for (int c2 = c1; c2 < m; c2++) {
                    // 计算列区间的贡献
                    long long col_total = 0;
                    for (int c = c1; c <= c2; c++) {
                        col_total += col_prefix[n][c];
                    }
                    
                    // 减去重复计算的部分
                    long long overlap = 0;
                    for (int r = r1; r <= r2; r++) {
                        overlap += (row_prefix[r][c2] - row_prefix[r][c1-1]);
                    }
                    
                    long long sum = row_total + col_total - overlap;
                    max_sum = max(max_sum, sum);
                }
            }
        }
    }
    
    cout << max_sum << endl;
    
    return 0;
}
