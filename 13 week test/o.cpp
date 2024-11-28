#include<bits/stdc++.h>

char s[100010], k[3][100010], t[200100];

void sss(char *abc, int n) {
    int len = strlen(abc);
    n %= len;
    if (n < 0) n += len;
    strcpy(t, abc + n);
    strncat(t, abc, n);
    strcpy(abc, t);
}

int main() {
    int a, b, c, kx[3][10001], n, k1, k2, k3;

    while (scanf("%d %d %d", &a, &b, &c) && (a || b || c)) {
        k1 = k2 = k3 = 0;
        scanf("%s", s);
        n = strlen(s);
        
        for (int i = 0; i < n; i++) {
            if ('a' <= s[i] && s[i] <= 'i') {
                k[0][k1] = s[i];
                kx[0][k1++] = i;
            } else if ('j' <= s[i] && s[i] <= 'r') {
                k[1][k2] = s[i];
                kx[1][k2++] = i;
            } else {
                k[2][k3] = s[i];
                kx[2][k3++] = i;
            }
        }

        k[0][k1] = k[1][k2] = k[2][k3] = '\0';
        
        sss(k[0], a);
        sss(k[1], b);
        sss(k[2], c);

        for (int i = 0; i < k1; i++) s[kx[0][i]] = k[0][i];
        for (int i = 0; i < k2; i++) s[kx[1][i]] = k[1][i];
        for (int i = 0; i < k3; i++) s[kx[2][i]] = k[2][i];

        printf("%s\n", s);
    }

    return 0;
}
