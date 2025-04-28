#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if(n==m)cout<<(long double)1/m;
    else cout<<(long double)1/(m+1);
    return 0;
}