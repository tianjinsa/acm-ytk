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

    // 计算第 m 次中奖代币的位置
    long long pos = (k % n) * m % n;

    // 由于数组从 0 开始，需要取模 n
    int winning_pos = pos % n;
    char winning_token = tokens[winning_pos];
    char new_token = next_char(winning_token);
    printf("%c\n", new_token);

    free(tokens);
    return 0;
}