#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a;
    char b;
    cin>>a>>b;
    switch(b)
    {
        case '+':
            cout<<a-1<<' '<<1;
            break;
        case '-':
            cout<<a+1<<' '<<1;
            break;
        case '*':
            cout<<a<<' '<<1;
            break;
    }
    return 0;
}