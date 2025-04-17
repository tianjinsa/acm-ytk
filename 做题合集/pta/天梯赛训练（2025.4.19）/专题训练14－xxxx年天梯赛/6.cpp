#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int nn=0;
    deque<int> q;
    while(getline(cin,s)&&s!="."){
        nn++;
        if(s.find("chi1 huo3 guo1")!=-1)q.push_back(nn);
    }
    cout<<nn<<endl;
    if(q.empty()){
        cout<<"-_-#"<<endl;
        return 0;
    }
    cout<<q.front()<<' '<<q.size()<<endl;
    return 0;
}