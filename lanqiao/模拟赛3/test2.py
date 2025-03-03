count_ones = [bin(s).count('1') for s in range(16)]
dp_prev = [1] * 16  # 初始状态，k=4时每个四位组合的数量为1

for k in range(5, 25):
    dp_current = [0] * 16
    for s_prev in range(16):
        cnt = count_ones[s_prev]
        # 尝试添加0
        if cnt <= 3:
            s_new = (s_prev << 1 | 0) & 0b1111
            dp_current[s_new] += dp_prev[s_prev]
        # 尝试添加1
        if cnt + 1 <= 3:
            s_new = (s_prev << 1 | 1) & 0b1111
            dp_current[s_new] += dp_prev[s_prev]
    dp_prev = dp_current

result = sum(dp_prev)
print(result)
