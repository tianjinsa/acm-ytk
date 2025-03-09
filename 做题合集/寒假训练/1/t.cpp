#include <iostream>
#include <string>
using namespace std;
string add(string a,string b){
    string c;
    int carry=0;
    int i=a.length()-1,j=b.length()-1;
    
    while (i>=0||j>=0||carry) {
        int sum=carry;
        if(i>=0)sum+=a[i]-'0';
        if(j>=0)sum+=b[j]-'0';
        carry=sum/10;
        sum%=10;
        c=(char)(sum<10?sum+'0':sum-10+'A')+c;
        i--,j--;
    }
    return c;
}
int main()
{
    int n;
    string a="0",b;
    while(cin>>b){
        a=add(a,b);
    }
    cout<<a;
    return 0;
}