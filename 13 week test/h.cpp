#include<bits/stdc++.h>
//using namespace std;
int kaisa(char ch,long long b)
{
    char a=0;
    if(ch>='A'&&ch<='Z'){
        a='A';
    }
    if(a==0){
        return ch;
    }
    ch-=a;
    b+=ch;
    while(b<0){
        b+=26;
    }
    b=b%26;
    b+=a;
    ch=b;
    return ch;
}
int main()
{
    char a[300];
    fgets(a,300,stdin);
    while(fgets(a,300,stdin)){
        for(int i=0;i<strlen(a);i++){
            a[i]=kaisa(a[i],-5);
        }
        a[strlen(a)-1]='\0';
        printf("%s\n",a);
        fgets(a,300,stdin);
        fgets(a,300,stdin);
        if(a[0]=='E'&&a[1]=='N'&&a[2]=='D'&&a[3]=='O'){
            break;
        }
    }
    return 0;
}