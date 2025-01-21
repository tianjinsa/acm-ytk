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
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        string a,b;
        cin>>a>>b;
        cout<<"Case "<<i<<":"<<endl;
        cout<<a<<" + "<<b<<" = "<<add(a,b)<<endl<<endl;
    }
    return 0;
}