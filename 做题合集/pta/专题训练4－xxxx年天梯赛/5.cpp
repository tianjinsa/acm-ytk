#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> in(n);
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        bool fl1=0;
        bool fl2=0;
        for(int j=0;j<n;j++){
            int t;
            cin>>t;
            if(t!=0){
                if(t==in[j]){
                    fl2=1;
                }
                else{
                    fl1=1;
                }
            }
        }
        if(!fl1&&fl2){
            cout<<"Da Jiang!!!"<<endl;
        } else{
            cout<<"Ai Ya"<<endl;
        }
    }
    
    return 0;
}