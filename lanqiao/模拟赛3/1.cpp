#include <iostream>
#include <stack>
using namespace std;
long long gcd(long long a,long long b)
{
    return (b==0)?a:gcd(b,a%b);
}

int main() {
    long long num = 2024;
    stack<int> ms;
    int i=1;
    while (ms.size()!=2024) {
        if(gcd(i,num)==1) {
            ms.push(i);
        }
        i++;
    }

    while (!ms.empty()) {
        cout << ms.top() << " ";
        ms.pop();
    }
    
    cout << endl;
    return 0;
}
