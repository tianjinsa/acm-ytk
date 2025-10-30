#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N=1;
    int n;
    while(cin>>n&&n){
        cout<<"Scenario #"<<N++<<'\n';
        int begin=0;
        vector<int>tpos(n+1,-1);
        unordered_map<int,int>pt;
        vector<deque<int>>que;
        for(int i=1;i<=n;i++){
            int t;
            cin>>t;
            for(int j=0;j<t;j++){
                int x;
                cin>>x;
                pt[x]=i;
            }
        }
        string op;
        while(cin>>op){
            if(op=="ENQUEUE"){
                int t;
                cin>>t;
                int tem=pt[t];
                if(tpos[tem]==-1){
                    tpos[tem]=que.size();
                    que.push_back(deque<int>());
                }
                que[tpos[tem]].push_back(t);
            }
            else if(op=="DEQUEUE"){
                int ptt=que[begin].front();
                cout<<ptt<<'\n';
                que[begin].pop_front();
                if(que[begin].empty()){
                    tpos[pt[ptt]]=-1;
                    begin++;
                }
            }
            else break;
        }
        cout<<'\n';
    }
    return 0;
}