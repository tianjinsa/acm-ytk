#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node *left,*right;
    Node(int x):val(x),left(0),right(0){}
};
Node* build(int preL,int preR,int inL,int inR,vector<int>&pre,vector<int>&mid,unordered_map<int,int>&mp){
    if(preL>preR || inL>inR) return 0;
    Node *root=new Node(pre[preL]);
    int rootIndex=mp[pre[preL]];
    int leftSize=rootIndex-inL;
    root->left=build(preL+1,preL+leftSize,inL,rootIndex-1,pre,mid,mp);
    root->right=build(preL+leftSize+1,preR,rootIndex+1,inR,pre,mid,mp);
    return root;
} 

int main()
{
    int n;
    cin>>n;
    vector<int>pre(n),mid(n);
    for(int i=0;i<n;i++)
        cin>>mid[i];
    for(int i=0;i<n;i++)
        cin>>pre[i];
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
        mp[mid[i]]=i;
    Node *root=build(0,n-1,0,n-1,pre,mid,mp);
    queue<Node*>q;
    q.push(root);
    bool fl=0;
    while(!q.empty()){
        Node *cur=q.front();
        q.pop();
        if(cur->right) q.push(cur->right);
        if(cur->left) q.push(cur->left);
        if(fl) cout<<" ";
        cout<<cur->val;
        fl=1;
    }
    return 0;
}