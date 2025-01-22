#include<bits/stdc++.h>
using namespace std;
void ai_prime(bool a[],int n)//艾氏筛素数表
{
    for(int i=2;i*i<=n;i++){
        if(a[i]==0){
            for(int j=i*i;j<n;j+=i){
                a[j]=1;
            }
        }
    }
}
int main()
{
    bool a[101]={0};
    a[0]=a[1]=1;
    ai_prime(a,100);
    string s;
    cin>>s;
    int b[26]={0};
    for(int i=0;i<s.length();i++){
        b[s[i]-'a']++;
    }
    int max,min;
    max=min=0;
    for(int i=0;i<26;i++){
        if(b[i]>max||max==0){
            max=b[i];
        }
        if(b[i]&&b[i]<min||min==0){
            min=b[i];
        }
    }
    if(a[max-min]==0){
        printf("Lucky Word\n%d",max-min);
    }
    else{
        printf("No Answer\n0");
    }
    return 0;
}