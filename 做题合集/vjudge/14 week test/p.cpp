#include <bits/stdc++.h>
// using namespace std;

char a[10001][2050];
    char temp[2050] = {0};

void add(char* result, const char* num1, const char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int carry = 0, i = len1 - 1, j = len2 - 1, k = 0;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        temp[k++] = (sum % 10) + '0';
        carry = sum / 10;
    }
    for (int l = 0; l < k; l++) {
        result[l] = temp[k - l - 1];
    }
    result[k] = '\0';
}

void f() {
    strcpy(a[1], "1");
    strcpy(a[2], "1");
    strcpy(a[3], "1");
    strcpy(a[4], "1");
    for (int i = 5; i < 10001; i++) {
        char temp1[2050] = {0}, temp2[2050] = {0};
        memset()
        add(temp1, a[i-1], a[i-2]);
        add(temp2, a[i-3], a[i-4]);
        add(a[i], temp1, temp2);
    }
}

int main() {
    f();
    for (int i = 1; i < 10001; i++) {
        printf("%s\n", a[i]);
    }
    return 0;
}