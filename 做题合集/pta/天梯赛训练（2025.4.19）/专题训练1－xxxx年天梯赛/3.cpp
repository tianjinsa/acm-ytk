#include <bits/stdc++.h>
using namespace std;
int main() {
    string a,b;
    getline(cin,a);
    getline(cin,b);
    for(auto i:a){
        if(b.find(i)==-1){
            printf("%c",i);
        }
    }
    return 0;

}