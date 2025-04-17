#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int>a,b;
    int n;
    cin>>n;
    int ans=0,max=0;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        if(a.empty()||t<a.top()){
            a.push(t);
        }
        else if(b.empty()||t>b.top()){
            b.push(t);
        }
        else{
            ans++;
            if(a.size()>max){
                max=a.size();
            }
            while(!a.empty()){
                a.pop();
            }
            while(!b.empty()&&b.top()>t){
                a.push(b.top());
                b.pop();
            }
            a.push(t);
        }
    }
    ans+=(!a.empty())+(!b.empty());
    if(b.size()>max){
        max=b.size();
    }
    if(a.size()>max){
        max=a.size();
    }
    cout<<ans<<' '<<max;
    return 0;
}