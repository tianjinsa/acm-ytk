#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    // 使用一维数组替代二维数组，减少缓存未命中
    long long* a = new long long[n*m + 1];
    
    // 读取矩阵
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[(i-1)*m + j];
        }
    }
    
    // 计算行和
    long long* row_sum = new long long[n+1]();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            row_sum[i] += a[(i-1)*m + j];
        }
    }
    
    // 计算列和
    long long* col_sum = new long long[m+1]();
    for(int j=1; j<=m; j++){
        for(int i=1; i<=n; i++){
            col_sum[j] += a[(i-1)*m + j];
        }
    }
    
    long long max_sum = LONG_LONG_MIN;
    
    // 预计算每个(r1,r2)区间的行和
    long long** row_interval_sum = new long long*[n+1];
    for(int i=0; i<=n; i++){
        row_interval_sum[i] = new long long[n+1]();
    }
    
    for(int r1=2; r1<n; r1++){
        for(int r2=r1; r2<n; r2++){
            row_interval_sum[r1][r2] = row_interval_sum[r1][r2-1] + row_sum[r2];
            if(r1 == r2) row_interval_sum[r1][r2] = row_sum[r1];
        }
    }
    
    // 优化：对每个行区间，预计算每列的交叉部分
    for(int r1=2; r1<n; r1++){
        for(int r2=r1; r2<n; r2++){
            // 当前行区间的总和
            long long rows_total = row_interval_sum[r1][r2];
            
            // 预计算每列与当前行区间的交叉部分
            long long* intersection = new long long[m+1]();
            for(int c=1; c<=m; c++){
                for(int r=r1; r<=r2; r++){
                    intersection[c] += a[(r-1)*m + c];
                }
            }
            
            // 对每个可能的列区间计算十字和
            for(int c1=2; c1<m; c1++){
                // 优化：计算列前缀和，避免重复计算
                long long col_prefix_sum = 0;
                for(int c2=c1; c2<m; c2++){
                    col_prefix_sum += col_sum[c2];
                    
                    // 计算列区间[c1,c2]和行区间[r1,r2]的交叉部分
                    long long cross_sum = 0;
                    for(int c=c1; c<=c2; c++){
                        cross_sum += intersection[c];
                    }
                    
                    // 十字和 = 行总和 + 列区间和 - 交叉部分
                    long long sum = rows_total + col_prefix_sum - cross_sum;
                    max_sum = max(max_sum, sum);
                }
            }
            
            delete[] intersection;
        }
    }
    
    cout << max_sum << endl;
    
    // 释放内存
    delete[] a;
    delete[] row_sum;
    delete[] col_sum;
    for(int i=0; i<=n; i++){
        delete[] row_interval_sum[i];
    }
    delete[] row_interval_sum;
    
    return 0;
}
