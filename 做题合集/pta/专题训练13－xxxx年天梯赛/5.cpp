#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    int t=0;
    while((t=s.find("6666666666"))!=-1){
        s.replace(t,s.find_first_not_of("6",t)-t,"27");
    }
    while((t=s.find("6666"))!=-1){
        s.replace(t,s.find_first_not_of("6",t)-t,"9");
    }
    cout<<s;
    return 0;
}