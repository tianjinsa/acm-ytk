#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,t;
    cin>>s>>t;
    int pos=1;
    bool fl=1;
    while((pos=s.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ",pos))!=-1) {
        if(t.find(s[pos-1])==-1) {
            fl=0;
            break;
        }
        pos++;
    }
    cout<<(fl?"Yes":"No");
    return 0;
}