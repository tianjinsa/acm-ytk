#include <stdio.h>  
  
// 函数来计算一个数的Collatz序列长度  
int collatz_length(int n) {  
    int length = 1;  
    while (n != 1) {  
        if (n % 2 == 0) {  
            n = n / 2;  
        } else {  
            n = 3 * n + 1;  
        }  
        length++;  
    }  
    return length;  
}  
  
int main() {  
    int i, j;  
    while (scanf("%d %d", &i, &j) == 2) {  
        int max_length = 0;  
        for (int k = i; k <= j; k++) {  
            int length = collatz_length(k);  
            if (length > max_length) {  
                max_length = length;  
            }  
        }  
        printf("%d %d %d\n", i, j, max_length);  
    }  
    return 0;  
}