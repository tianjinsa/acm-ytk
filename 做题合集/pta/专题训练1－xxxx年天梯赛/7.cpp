#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    char c;
    cin>>n>>c;
    string s(n,c);
    for(int i=0;i<round(1.0*n/2);i++){
        cout<<s<<endl;
    }
    return 0;
}