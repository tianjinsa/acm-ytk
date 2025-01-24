#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MOD=1e9 + 7;
int n;
string grid[3];
long long ans;
bool check(int row, int col) {
    bool used[10]={false};
    int startCol=(col/3) * 3;
    for(int i=0; i < 3; i++) {
        for(int j=startCol; j < min(startCol + 3, n); j++) {
            if(grid[i][j] != '?') {
                int num=grid[i][j] - '0';
                if(used[num]) return false;
                used[num]=true;
            }
        }
    }
    return true;
}

void dfs(int pos) {
    if(pos == 3 * n) {
        ans=(ans + 1) % MOD;
        return;
    }
    
    int row=pos / n;
    int col=pos % n;
    
    if(grid[row][col] != '?') {
        dfs(pos + 1);
        return;
    }
    
    for(int i=1; i <= 9; i++) {
        grid[row][col]=i + '0';
        if(check(row, col)) {
            dfs(pos + 1);
        }
        grid[row][col]='?';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i=0; i < 3; i++) {
            cin >> grid[i];
        }
        
        ans=0;
        dfs(0);
        cout << ans << endl;
    }
    return 0;
}
