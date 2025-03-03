# 初始化 dp 数组
dp = [[[[[0 for _ in range(2)] for _ in range(2)] for _ in range(2)] for _ in range(2)] for _ in range(25)]

# 初始化长度为 4 的所有 01 串
for a in range(2):
    for b in range(2):
        for c in range(2):
            for d in range(2):
                dp[4][a][b][c][d] = 1

# 动态规划过程
for i in range(5, 25):
    for a in range(2):
        for b in range(2):
            for c in range(2):
                for d in range(2):
                    # 尝试添加 0
                    dp[i][b][c][d][0] += dp[i - 1][a][b][c][d]
                    # 尝试添加 1，需要判断是否满足条件
                    if a + b + c + d + 1 <= 3:
                        dp[i][b][c][d][1] += dp[i - 1][a][b][c][d]

# 计算最终结果
result = 0
for a in range(2):
    for b in range(2):
        for c in range(2):
            for d in range(2):
                result += dp[24][a][b][c][d]

print(result)