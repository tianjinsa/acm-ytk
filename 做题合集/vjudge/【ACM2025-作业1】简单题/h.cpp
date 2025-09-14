#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> a(10001),sum(10001);
    int cnt=0,num=1;
    while (cnt<10000) {
        for (int j=0;j<num&&cnt<10000;++j) {
            ++cnt;
            a[cnt]=num;
        }
        ++num;
    }
    for (int i=1;i<=10000;++i) {
        sum[i]=sum[i-1]+a[i];
    }

    int n;
    while (cin>>n&&n) {
        cout<<n<<" "<<sum[n]<<'\n';
    }
    return 0;
}