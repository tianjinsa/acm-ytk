#include<bits/stdc++.h>
using namespace std;
deque<int> d;
int n,m,k;
bool cha(deque<int>&a){
    deque<int> t=d;
    stack<int> s;
    while(!a.empty()){
        if(!s.empty()&&s.top()==a.front()){
            s.pop();
            a.pop_front();
        }
        else if(!t.empty()&&t.front()==a.front()){
            t.pop_front();
            a.pop_front();
        }
        else if(!t.empty()&&s.size()<m-1){
            s.push(t.front());
            t.pop_front();
        }
        else{
            return 0;
        }
    }
    return 1;
}
int main()
{
    cin>>m>>n>>k;
    for(int i=1;i<=n;i++)d.push_back(i);
    while(k--){
        deque<int> a;
        for(int i=0;i<n;i++){
            int t;
            cin>>t;
            a.push_back(t);
        }
        if(cha(a)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}