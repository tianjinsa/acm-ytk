#include<bits/stdc++.h>
using namespace std;

int main()
{
    
    int n;
    cin>>n;
    while(n--){
        bool fl=1;
        vector<set<int>> a(9,{1,2,3,4,5,6,7,8,9});
        vector<set<int>> b(9,{1,2,3,4,5,6,7,8,9});
        vector<set<int>> c(9,{1,2,3,4,5,6,7,8,9});
        int t;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cin>>t;
                a[i].erase(t);
                b[j].erase(t);
                c[(i/3)*3+(j/3)].erase(t);
                if(!(1<=t&&t<=9)){
                    fl=0;
                }
            }
        }
        if(!fl){
            cout<<0<<endl;
            continue;
        }
        int sum=0;
        for(auto t:a){
            sum+=t.size();
        }
        for(auto t:b){
            sum+=t.size();
        }
        for(auto t:c){
            sum+=t.size();
        }
        if(sum){
            cout<<0<<endl;
        }
        else{
            cout<<1<<endl;
        }
    }
    return 0;
}