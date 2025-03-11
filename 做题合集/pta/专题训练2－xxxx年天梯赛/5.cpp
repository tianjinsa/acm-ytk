#include<bits/stdc++.h>
using namespace std;

// 计算KMP算法的next数组
vector<int> getNext(const string& pattern) {
    int m = pattern.size();
    vector<int> next(m, 0);
    for(int i = 1, j = 0; i < m; i++) {
        while(j > 0 && pattern[i] != pattern[j]) {
            j = next[j - 1];
        }
        if(pattern[i] == pattern[j]) {
            j++;
        }
        next[i] = j;
    }
    return next;
}

// KMP搜索算法，返回找到的位置
int kmpSearch(const string& text, const string& pattern, int startPos, vector<int>& next) {
    int n = text.size(), m = pattern.size();
    if(m == 0) return -1;
    
    for(int i = startPos, j = 0; i < n; i++) {
        while(j > 0 && text[i] != pattern[j]) {
            j = next[j - 1];
        }
        if(text[i] == pattern[j]) {
            j++;
        }
        if(j == m) {
            return i - m + 1;
        }
    }
    return -1;
}

int main()
{
    int n,k;
    cin>>n;
    vector<string> ss;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        ss.push_back(s);
    }
    cin>>k;
    string ans;
    cin.ignore(1,'\n');
    getline(cin,ans);
    int sum=0;
    for(auto it:ss){
        vector<int> next = getNext(it);
        int t=0;
        while((t=kmpSearch(ans, it, t, next))!=-1){
            sum++;
            ans.replace(t,it.size(),"<censored>");
            t+=10;
        }
        
        if(sum>=k) break; // 提前终止循环
    }
    if(sum<k){
        cout<<ans<<endl;
    }
    else{
        cout<<sum<<endl;
        cout<<"He Xie Ni Quan Jia!";
    }
    return 0;
}