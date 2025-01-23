#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin>>q;
    string s;
    cin>>s;
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            string str;
            cin>>str;
            s+=str;
            cout<<s<<endl;
        }
        else if(op==2){
            int a,b;
            cin>>a>>b;
            s=s.substr(a,b);
            cout<<s<<endl;
        }
        else if(op==3){
            int a;
            string str;
            cin>>a>>str;
            s.insert(a,str);
            cout<<s<<endl;
        }
        else if(op==4){
            string str;
            cin>>str;
            int pos=s.find(str);
            cout<<pos<<endl;
        }
    }
    return 0;
}