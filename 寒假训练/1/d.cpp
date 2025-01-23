#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a,b;
    cin>>a>>b;
    int carry=0,j=b.size()-1;
    for(int i=a.size()-1;i>=0;i--){
        int x=a[i]-'0';
        int y=(j>=0?b[j--]-'0':0)+carry;
        carry=0;
        if(x<y){
            x+=10;
            carry=1;
        }
        a[i]=(x-y)+'0';
    }
    int tt=0;
    while(tt<a.size()-1&&a[tt]=='0'){
        tt++;
    }
    a=a.substr(tt);
    cout<<a<<endl;
    return 0;
}