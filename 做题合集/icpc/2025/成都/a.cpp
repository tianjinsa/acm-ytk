#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    n=max(n,m);
    string s = "UDLR";
    srand(time(NULL));
    for (int i = 1; i <= 50000/4; i++)
        putchar(s[rand() % 4]);
    for(int i=0;i<50000/n/12/4;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"LD";
        }
        for(int j=0;j<n;j++)
        {
            cout<<"LU";
        }
        for(int j=0;j<n;j++)
        {
            cout<<"RU";
        }
        for(int j=0;j<n;j++)
        {
            cout<<"LD";
        }
        for(int j=0;j<n;j++)
        {
            cout<<"LU";
        }
        for(int j=0;j<n;j++)
        {
            cout<<"RD";
        }
    }
    srand(time(NULL));
    for (int i = 1; i <= 50000/4; i++)
        putchar(s[rand() % 4]);
    for(int i=0;i<50000/n/12/4;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"LD";
        }
        for(int j=0;j<n;j++)
        {
            cout<<"LU";
        }
        for(int j=0;j<n;j++)
        {
            cout<<"RU";
        }
        for(int j=0;j<n;j++)
        {
            cout<<"LD";
        }
        for(int j=0;j<n;j++)
        {
            cout<<"LU";
        }
        for(int j=0;j<n;j++)
        {
            cout<<"RD";
        }
    }
    
    return 0;
}