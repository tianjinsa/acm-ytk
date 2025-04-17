#include<bits/stdc++.h>
using namespace std;
deque<string>a,b;
deque<int>c;
int main()
{
    int n;
    cin>>n;
    while(n--){
        int x;
        string s;
        cin>>x>>s;
        if(x){
            a.push_back(s);
        }
        else{
            b.push_back(s);
        }
        c.push_back(x);
    }
    for(auto i:c){
        if(i){
            cout<<a.front()<<" "<<b.back()<<endl;
            a.pop_front();
            b.pop_back();
        }
        else{
            cout<<b.front()<<" "<<a.back()<<endl;
            b.pop_front();
            a.pop_back();
        }
        if(a.empty())
            break;
    }
    return 0;
}