#include <bits/stdc++.h>
using namespace std;

vector<int> heap;
unordered_map<int, int> mp;

void inh(int x){
    heap.push_back(x);
    int pos=heap.size()-1;
    mp[x]=pos;
    while(pos>0){
        int fa=(pos-1)/2;
        if(heap[fa]>heap[pos]){
            swap(heap[fa],heap[pos]);
            mp[heap[fa]]=fa;
            mp[heap[pos]]=pos;
            pos=fa;
        }
        else{
            break;
        }
    }
}
int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        inh(val);
    }
    cin.ignore(1,'\n');
    string s;
    while(getline(cin,s)){
        bool fl=0;
        int x,y;
        stringstream ss(s);
        string out;
        ss>>x;
        if(s.find("root")!=-1){
            if(mp[x]==0)fl=1;
            cout<<(fl?"T":"F")<<endl;
        }
        else if(s.find("siblings")!=-1){
            ss>>out>>y;
            if((mp[x]+1)/2==(mp[y]+1)/2&&mp[x]!=mp[y])fl=1;
            cout<<(fl?"T":"F")<<endl;
        }
        else if(s.find("parent")!=-1){
            ss>>out>>out>>out>>out>>y;
            if(mp[x]==((mp[y]+1)/2)-1)fl=1;
            cout<<(fl?"T":"F")<<endl;
        }
        else if(s.find("child")!=-1){
            ss>>out>>out>>out>>out>>y;
            if(((mp[x]+1)/2-1)==mp[y])fl=1;
            cout<<(fl?"T":"F")<<endl;
        }
    }

    return 0;
}