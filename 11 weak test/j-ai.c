#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char sss(char x) {
    if (x == 'Z')
        return 'A';
    return x + 1;
}

void caru(char *a, int x, char y, int *n) {
    memmove(a + x + 1, a + x, (*n - x) * sizeof(char));
    a[x] = y;
    (*n)++;
}

int main() {
    int k, m, n;
    while (scanf("%d%d%d", &n, &k, &m) != EOF) {
        char *s = (char *)malloc((n + m) * sizeof(char));
        scanf("%s", s);
        int x = 0;
        for (int i = 0; i < m - 1; i++) {
            x = (x + k) % n;
            caru(s, x + 1, sss(s[x]), &n);
            x++;
        }
        x = (x + k) % n;
        printf("%c\n", sss(s[x]));
        free(s);
    }
    return 0;
}