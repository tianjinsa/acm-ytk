#include<bits/stdc++.h>
using namespace std;
string add(string a,string b,int o){//o进制加法
    string c;
    int carry=0;
    int i=a.length()-1,j=b.length()-1;
    
    while (i>=0||j>=0||carry) {
        int sum=carry;
        if(i>=0)sum+=(isdigit(a[i])?a[i]-'0':a[i]-'A'+10);
        if(j>=0)sum+=(isdigit(b[j])?b[j]-'0':b[j]-'A'+10);
        carry=sum/o;
        sum%=o;
        c=(char)(sum<10?sum+'0':sum-10+'A')+c;
        i--,j--;
    }
    return c;
}
int main()
{
    int n;
    string s;
    cin>>n>>s;
    for(int i=1;i<=31;i++){
        string t=s;
        reverse(t.begin(),t.end());
        if(t==s){
            printf("STEP=%d\n",i-1);
            return 0;
        }
        s=add(s,t,n);
    }
    printf("Impossible!\n");
    return 0;
}