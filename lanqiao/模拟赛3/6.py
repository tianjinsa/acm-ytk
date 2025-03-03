S = "ANQNANBNQNANQNQNBNINQNQNANQNINANQNANBNQNANQNQNBNBNQNQNANQNINANQNANBNQNANQNQNBNINQNQNANQNINBNQNANBNQN"
max_score = 0
best_substring = ""
for length in range(1, 11):
    for start in range(len(S) - length + 1):
        sub = S[start:start+length]
        count = S.count(sub)
        score = length * count
        if score > max_score:
            max_score = score
            best_substring = sub
        elif score == max_score:
            best_substring = min(best_substring, sub)
print(best_substring)