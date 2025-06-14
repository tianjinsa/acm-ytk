#include<bits/stdc++.h>
using namespace std;
struct node{
    int v;
    node *l,*r;
    node(int n):v(n),l(nullptr),r(nullptr) {}
};

void add(node* &root,int a){
    if(!root){
        root = new node(a);
    }
    else{
        if(a >= root->v) add(root->r,a);
        else add(root->l,a);
    }
}
vector<int> ans;
void dfs1(node* root){
    if(!root) return;
    ans.push_back(root->v);
    dfs1(root->l);
    dfs1(root->r);
}
void dfs2(node* root){
    if(!root) return;
    ans.push_back(root->v);
    dfs2(root->r);
    dfs2(root->l);
}
void dfs3(node* root){
    if(!root) return;
    dfs3(root->l);
    dfs3(root->r);
    ans.push_back(root->v);
}
void dfs4(node* root){
    if(!root) return;
    dfs4(root->r);
    dfs4(root->l);
    ans.push_back(root->v);
}
int main()
{
    node* root = nullptr;
    int n;
    vector<int> tt;
    cin>>n;
    while(cin >> n){
        add(root, n);
        tt.push_back(n);
    }
    bool fl=0;
    dfs1(root);
    if(ans==tt){
        cout << "YES" << endl;
        fl=1;
        ans.clear();
        dfs3(root);
        for(auto i: ans){
            if(fl)fl=0;
            else cout << " ";
            cout << i;
        }
        return 0;
    }
    ans.clear();
    dfs2(root);
    if(ans==tt){
        cout << "YES" << endl;
        fl=1;
        ans.clear();
        dfs4(root);
        for(auto i: ans){
            if(fl)fl=0;
            else cout << " ";
            cout << i;
        }
        return 0;
    }
    cout << "NO";
    return 0;
}