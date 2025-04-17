#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    stack<int> dig,flg;
    while(n--){
        int t;
        cin>>t;
        dig.push(t);
    }
    char t;
    while(cin>>t){
        flg.push(t);
    }
    while(dig.size()!=1){
        int a=dig.top();dig.pop();
        int b=dig.top();dig.pop();
        if(flg.top()=='/'){
            if(a==0){
                cout<<"ERROR: "<<b<<"/0"<<endl;
                return 0;
            }
            dig.push(b/a);
        }
        else if(flg.top()=='*'){
            dig.push(b*a);
        }
        else if(flg.top()=='-'){
            dig.push(b-a);
        }
        else if(flg.top()=='+'){
            dig.push(b+a);
        }
        flg.pop();
    }
    cout<<dig.top()<<endl;
    return 0;
}