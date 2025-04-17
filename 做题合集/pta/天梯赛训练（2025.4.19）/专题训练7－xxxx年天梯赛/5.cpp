#include<bits/stdc++.h>
using namespace std;
set<int>a[6] = {{1,2,3,4,5,6},{1,2,3,4,5,6},{1,2,3,4,5,6},{1,2,3,4,5,6},{1,2,3,4,5,6},{1,2,3,4,5,6}};
int main()
{
    int aa;
    for(int i=0;i<6;i++){
        cin>>aa;
        a[i].erase(aa);
    }
    cin>>aa;
    aa--;
    while(aa--){
        for(int i=0;i<6;i++){
            a[i].erase(prev(a[i].end()));
        }
    }
    for(int i=0;i<6;i++){
        if(i)cout<<' ';
        cout<<*prev(a[i].end());
    }

    return 0;
}