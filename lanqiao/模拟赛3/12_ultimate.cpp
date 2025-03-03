#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    // 使用一维数组模拟二维数组，提高缓存命中率
    int* a = new int[n*m + 1];
    
    // 读取矩阵数据
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[(i-1)*m + j];
        }
    }
    
    // 预计算二维前缀和 - 优化：直接使用一维数组
    long long* prefix_sum = new long long[(n+1)*(m+1)]();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            prefix_sum[i*(m+1)+j] = prefix_sum[(i-1)*(m+1)+j] + prefix_sum[i*(m+1)+j-1] 
                                  - prefix_sum[(i-1)*(m+1)+j-1] + a[(i-1)*m+j];
        }
    }
    
    // 获取子矩阵和的辅助函数
    auto get_sum = [&](int r1, int c1, int r2, int c2) -> long long {
        return prefix_sum[r2*(m+1)+c2] - prefix_sum[r2*(m+1)+c1-1] 
             - prefix_sum[(r1-1)*(m+1)+c2] + prefix_sum[(r1-1)*(m+1)+c1-1];
    };
    
    long long max_sum = LONG_LONG_MIN;
    
    // 针对问题特点：n较小，m较大的特性优化循环结构
    #pragma omp parallel for collapse(2) reduction(max:max_sum)
    for(int r1=2; r1<n; r1++){
        for(int r2=r1; r2<n; r2++){
            // 计算行[r1,r2]的和
            long long row_sum = get_sum(r1, 1, r2, m);
            
            // 优化：使用滑动窗口处理列区间
            for(int c1=2; c1<m; c1++){
                // 计算整个列（从1到n）的和，减去与行[r1,r2]的交叉部分
                long long col_contribution = 0;
                
                for(int c2=c1; c2<m; c2++){
                    // 当前列的贡献 = 全列和 - 与选定行的交叉部分
                    long long col_sum = get_sum(1, c2, n, c2);
                    col_contribution += col_sum;
                    
                    // 计算整个列区间[c1,c2]与行区间[r1,r2]的交叉部分
                    long long cross_section = get_sum(r1, c1, r2, c2);
                    
                    // 十字形区域和 = 行和 + 列区间贡献 - 交叉部分
                    long long total_sum = row_sum + col_contribution - cross_section;
                    max_sum = max(max_sum, total_sum);
                }
            }
        }
    }
    
    cout << max_sum << endl;
    
    delete[] a;
    delete[] prefix_sum;
    
    return 0;
}
