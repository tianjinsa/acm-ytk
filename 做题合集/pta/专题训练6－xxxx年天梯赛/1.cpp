#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a,b,s;
    getline(cin,s);
    int p=s.find(' ');
    a=s.substr(0,p);
    b=s.substr(p+1);
    bool fl1=1,fl2=1;
    for(auto i:a){
        if(!isdigit(i)){
            fl1=0;
            break;
        }
    }
    for(auto i:b){
        if(!isdigit(i)){
            fl2=0;
            break;
        }
    }
    int aa,bb;
    if(fl1&&a.size()<=4){
        aa=stoi(a);
        if(aa<1||aa>1000)fl1=0;
    }
    else fl1=0;
    if(fl2&&b.size()<=4){
        bb=stoi(b);
        if(bb<1||bb>1000)fl2=0;
    }
    else fl2=0;
    cout<<(fl1?a:"?")<<" + "<<(fl2?b:"?")<<" = "<<(fl1&&fl2?to_string(aa+bb):"?")<<endl;
    return 0;
}