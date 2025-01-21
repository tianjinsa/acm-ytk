#include<bits/stdc++.h>
using namespace std;

int main()
{
    __int128 a;
    string s;
    cin >> s;
    a = 0;
    for(int i=0;i<s.length();i++){
        a=a*10+(s[i]-'0');
    }
    bool fl=1;
    for(int i=2;i<=9;i++){
        if(a%i==0){
            printf("%d ",i);
            fl=0;
        }
    }
    if(fl)printf("none");
    return 0;
}