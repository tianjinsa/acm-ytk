#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a,b;
    cin>>a;
    cin.ignore();
    getline(cin,b);
    for(int i=0;i<a.length();i++){
        if(a[i]>='A'&&a[i]<='Z'){
            a[i]=a[i]-'A'+'a';
        }
    }
    for(int i=0;i<b.length();i++){
        if(b[i]>='A'&&b[i]<='Z'){
            b[i]=b[i]-'A'+'a';
        }
    }
    a=" "+a+" ";
    b=" "+b+" ";
    int pos=0,ans=0;
    int ans2=b.find(a);
    while((pos=b.find(a,pos))!=-1){
        ans++;
        pos++;
    }
    if(ans==0){
        printf("-1");
        return 0;
    }
    printf("%d %d",ans,ans2);
    return 0;
}