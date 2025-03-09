#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    int all=0;
    string ans1=s;
    for(char &c:ans1){
        if(isalpha(c)){
            c='.';
            all++;
        }
    }
    cout<<ans1<<endl;

    int n=(int)round(all/3.0);
    int t=0;
    string ans2=ans1;
    for(int i=0;i<(int)s.size();i++){
        if(isalpha(s[i])){
            t++;
            if(t<=n){
                ans2[i]=s[i];
            }
        }
    }
    cout<<ans2<<endl;

    string ans3=ans2;
    bool fl=0;
    for(int i=0;i<(int)s.size();i++){
        if(ans3[i]=='.'&&isalpha(s[i])){
            char tt=tolower(s[i]);
            if(tt=='a'||tt=='e'||tt=='i'||tt=='o'||tt=='u'){
                ans3[i]=s[i];
                fl=true;
            }
        }
    }
    if(!fl){
        ans3=ans1;
        n=(int)round(2*all/3.0);
        t=0;
        for(int i=0;i<(int)s.size();i++){
            if(isalpha(s[i])){
                t++;
                if(t<=n){
                    ans3[i]=s[i];
                }
            }
        }
    }
    cout<<ans3<<"\n";

    return 0;
}

