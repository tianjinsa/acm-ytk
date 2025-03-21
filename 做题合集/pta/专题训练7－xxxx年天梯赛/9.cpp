#include<bits/stdc++.h>
using namespace std;
stack<int> s;
deque<int> q;
vector<deque<int>> out;
int main()
{
    int N,M,K;
    cin>>N>>M>>K;
    while(N--){
        int t;
        cin>>t;
        q.push_back(t);
    }
    while(!s.empty()||!q.empty()){
        deque<int> temp;
        if(!s.empty()){
            temp.push_back(s.top());
            s.pop();
        }
        else{
            temp.push_back(q.front());
            q.pop_front();
        }
        while(temp.size()<K){
            if(!s.empty()&&s.top()<=temp.back()){
                temp.push_back(s.top());
                s.pop();
            }
            else if(!q.empty()&&q.front()<=temp.back()){
                temp.push_back(q.front());
                q.pop_front();
            }
            else if(!q.empty()&&s.size()<M){
                s.push(q.front());
                q.pop_front();
            }
            else{
                break;
            }
        }
        out.push_back(temp);
    }
    for(auto& ss:out){
        bool fl=0;
        while(!ss.empty()){
            if(fl)cout<<' ';
            fl=1;
            cout<<ss.front();
            ss.pop_front();
        }
        cout<<endl;
    }
    return 0;
}