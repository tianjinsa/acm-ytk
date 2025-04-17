#include<bits/stdc++.h>
using namespace std;

string check(string& s){
    if(s.length()<6){
        return "Your password is tai duan le.";
    }
    
    bool fl1=0;
    bool fl2=0;
    bool fl3=0;
    for(char c:s){
        if(isdigit(c)){
            fl1=1;
        }
        else if(isalpha(c)){
            fl2=1;
        }
        else if(c != '.'){
            fl3=1;
            break;
        }
    }
    
    if(fl3){
        return "Your password is tai luan le.";
    }
    if(!fl1){
        return "Your password needs shu zi.";
    }
    if(!fl2){
        return "Your password needs zi mu.";
    }
    
    return "Your password is wan mei.";
}

int main()
{
    int n;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        string s;
        getline(cin,s);
        cout<<check(s)<<endl;
    }
    
    return 0;
}