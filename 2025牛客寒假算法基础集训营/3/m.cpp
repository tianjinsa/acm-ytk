#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    map<char,int>mp;
    for (char c:s)mp[c]++;
    if (mp['n']==1&&mp['o']==2&&mp['w']==1&&mp['c']==1&&mp['d']==1&&mp['e']==1&&mp['r']==1)
        cout << "happy new year" << endl;
    else
        cout << "I AK IOI" << endl;
    return 0;
}