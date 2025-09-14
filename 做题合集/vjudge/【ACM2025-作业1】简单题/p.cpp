#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    while(cin>>s&&s!="0")
    {
        long long r=0;
        reverse(s.begin(),s.end());
        long long k=2;
        for(auto &c:s)
        {
            r+=(c-'0')*(k-1);
            k*=2;
        }
        cout<<r<<'\n';
    }
    return 0;
}
