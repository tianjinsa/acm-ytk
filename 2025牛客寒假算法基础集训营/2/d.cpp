#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    string s; cin >> s;

    vector<int> pi(n, 0);
    for(int i = 1; i < n; i++){
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]) j = pi[j - 1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }

    int length = pi[n - 1];
    bool found = false;
    while(length > 0) {
        for(int i = 0; i < n - 1; i++){
            if(pi[i] == length){
                found = true;
                break;
            }
        }
        if(found) {
            cout << length << "\n";
            return 0;
        }
        length = pi[length - 1];
    }

    cout << 0 << "\n";
    return 0;
}