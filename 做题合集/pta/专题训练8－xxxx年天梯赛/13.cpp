#include<bits/stdc++.h>
using namespace std;

vector<string> svc(const string& s){
    vector<string> all;
    string t;
    istringstream ss(s);
    while(getline(ss,t,'.')){
        all.push_back(t);
    }
    return all;
}
unordered_set<string> all;
int main(){
    int n;
    cin>>n;
    
    vector<string> num(n);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    
    set<string> all;
    for(const string& n:num){
        vector<string> tt=svc(n);
        for(const string& s:tt){
            all.insert(s);
        }
    }
    
    // 构建有向图
    map<string, set<string>> graph;// graph[a]={b,c} 表示 a < b 且 a < c
    map<string, set<string>> reverseGraph;// reverseGraph[a]={b,c} 表示 b < a 且 c < a
    
    for(int i=0;i < n-1;i++){
        vector<string> symbols1=svc(num[i]);
        vector<string> symbols2=svc(num[i+1]);
        int len=min(symbols1.size(), symbols2.size());
        bool found=false;
        for(int j=0;j < len;j++){
            if(symbols1[j] != symbols2[j]){
                graph[symbols1[j]].insert(symbols2[j]);
                reverseGraph[symbols2[j]].insert(symbols1[j]);
                found=true;
                break;
            }
        }
    }
    
    // 记录每个符号的入度
    map<string, int> indegree;
    for(const auto& s : all){
        indegree[s]=reverseGraph[s].size();
    }
    
    // 执行拓扑排序
    priority_queue<string, vector<string>, greater<string>> zeroDegree;// 优先队列确保按字典序获取入度为0的节点
    for(const auto& s : all){
        if(indegree[s] == 0){
            zeroDegree.push(s);
        }
    }
    
    vector<string> result;
    while(!zeroDegree.empty()){
        string curr=zeroDegree.top();
        zeroDegree.pop();
        result.push_back(curr);
        
        for(const string& next : graph[curr]){
            indegree[next]--;
            if(indegree[next] == 0){
                zeroDegree.push(next);
            }
        }
    }
    
    // 输出结果
    for(int i=0;i < result.size();i++){
        if(i > 0) cout << ".";
        cout << result[i];
    }
    cout << endl;
    
    return 0;
}