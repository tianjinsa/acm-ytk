#include <stdio.h>
#include <stdlib.h>

char next_char(char x) {
    if (x == 'Z')
        return 'A';
    return x + 1;
}

int main() {
    int n, k;
    long long m;
    scanf("%d%d%lld", &n, &k, &m);
    char *tokens = (char *)malloc((n + 1) * sizeof(char));
    scanf("%s", tokens);

    long long pos = 0;
    for (long long i = 1; i <= m; i++) {
        pos = (pos + k) % (n + i - 1);
    }

    // 计算最终中奖代币的位置
    int winning_pos = pos % n;
    char winning_token = tokens[winning_pos];
    char new_token = next_char(winning_token);
    printf("%c\n", new_token);

    free(tokens);
    return 0;
}