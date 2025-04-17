#include<bits/stdc++.h>
using namespace std;
bool ss(int a,int b){
    if(a<15||20<a)return 0;
    if(b<50||b>70)return 0;
    return 1;
}
int main()
{
    int n;
    cin>>n;
    while(n--){
        string s;
        int a,b;
        cin>>s>>a>>b;
        if(!ss(a,b))cout<<s<<endl;

    }
    return 0;
}