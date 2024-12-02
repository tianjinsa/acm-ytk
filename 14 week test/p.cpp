#include<bits/stdc++.h>
//using namespace std;
// long long a[500];
// void f()
// {
//     a[1]=1;
//     a[2]=1;
//     a[3]=1;
//     a[4]=1;
//     for(int i=5;i<500;i++){
//         a[i]=a[i-1]+a[i-2]+a[i-3]+a[i-4];
//     }
// }
// int main()
// {
//     int n;
//     f();
//     while(scanf("%d",&n)!=EOF){
//         printf("%lld\n",a[n]);
//     }
//     return 0;
// }
using namespace std;

vector<string> a(10001);

string addStrings(const string &num1, const string &num2) {
    string result;
    int carry = 0, i = num1.size() - 1, j = num2.size() - 1;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        result += (sum % 10) + '0';
        carry = sum / 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

void f() {
    a[1] = "1";
    a[2] = "1";
    a[3] = "1";
    a[4] = "1";
    for (int i = 5; i < 10001; i++) {
        a[i] = addStrings(addStrings(a[i-1], a[i-2]), addStrings(a[i-3], a[i-4]));
    }
}

int main() {
    f();
    for (int i = 1; i < 10001; i++) {
        cout << "a[" << i << "] = " << a[i] << endl;
    }
    return 0;
}