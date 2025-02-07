#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    while(N--){
        int len1,len2;
        cin>>len1>>len2;
        int a[26]={0},b[26]={0};
        for(int i=0;i<len1;i++){
            char c;
            cin>>c;
            a[c-'a']++;
        }
        for(int i=0;i<len2;i++){
            char c;
            cin>>c;
            b[c-'a']++;
        }
        int ans=0,tt;
        if(len1>len2){
            swap(len1,len2);
            swap(a,b);
        }
        for(int i=0;i<26;i++){
            ans=min(a[i],b[i]);
            a[i]-=ans;
            b[i]-=ans;
        }
        ans=0;
        tt=(len1+len2)/2-len1;
        for(int i=0;i<26;i++){
            ans=min(b[i]/2*2,tt*2);
            b[i]-=ans;
            tt-=ans/2;
        }
        ans=0;
        for(int i=0;i<26;i++){
            ans+=a[i]+b[i];
        }
        cout<<ans/2<<endl;
    }
    return 0;
}