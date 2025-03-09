#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char b[]="10X98765432";
    int n;
    cin>>n;
    bool ans2=1;
    while(n--){
        string s;
        cin>>s;
        bool fl=1;
        for(int i=0;i<17;i++){
            if(s[i]<'0'||s[i]>'9'){
                ans2=fl=0;
                cout<<s<<endl;
                break;
            }
        }
        if(!fl) continue;
        int sum=0;
        for(int i=0;i<17;i++){
            sum+=(s[i]-'0')*a[i];
        }
        sum%=11;
        if(b[sum]==s[17]){
            continue;
        }
        else{
            ans2=0;
            cout<<s<<endl;
        }
    }
    if(ans2){
        cout<<"All passed";
    }
    return 0;
}