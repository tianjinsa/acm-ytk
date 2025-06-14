#include<bits/stdc++.h>
using namespace std;
int expandAroundCenter(string& s, int left, int right) {
    int L = left;
    int R = right;
    while (L >= 0 && R < s.length() && s[L] == s[R]) {
        L--;
        R++;
    }
    return R - L - 1;
}

int main() {
    string s;
    getline(cin, s);

    if (s.empty()) {
        cout << 0 << endl;
        return 0;
    }

    int maxLength = 0;
    for (int i = 0; i < s.length(); ++i) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        maxLength = max(maxLength, max(len1, len2));
    }
    cout << maxLength << endl;
    return 0;
}