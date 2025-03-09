#include<iostream>
#include<string>
using namespace std;

string mult(string a,string b){
    string result(a.length()+b.length(),'0');
    for(int i=a.length()-1;i>=0;i--){
        int carry=0;
        for(int j=b.length()-1;j>=0;j--){
            int sum=(result[i+j+1]-'0')+(a[i]-'0')*(b[j]-'0')+carry;
            result[i+j+1]=(sum%10)+'0';
            carry=sum/10;
        }
        result[i]+=carry;
    }
    while(result[0]=='0'&&result.length()>1){
        result.erase(0,1);
    }
    return result;
}

int main()
{
    string a,b;
    cin>>a>>b;
    cout<<mult(a,b)<<endl;
    return 0;
}