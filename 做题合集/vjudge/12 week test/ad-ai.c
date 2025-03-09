#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 检查两个字符串是否是循环移位
int isCyclicShift(char *original, char *shifted) {
    int len = strlen(original);
    char temp[2 * len + 1];
    strcpy(temp, original);
    strcat(temp, original);
    return strstr(temp, shifted) != NULL;
}

// 判断给定的数字串是否是循环数
int isCyclicNumber(char *num) {
    int len = strlen(num);
    long long original = atoll(num);
    char multiplied[61];

    for (int i = 2; i <= len; i++) {
        long long product = original * i;
        sprintf(multiplied, "%0*lld", len, product);
        if (!isCyclicShift(num, multiplied)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char num[61];
    scanf("%s", num);

    if (isCyclicNumber(num)) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}