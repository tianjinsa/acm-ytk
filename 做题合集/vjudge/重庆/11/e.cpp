#include<bits/stdc++.h>
using namespace std;


struct node{
    int v;
    node* l,*r;
};
vector<node> buf;
node* maketree(int depth)
{
    node* root = &buf.emplace_back(node());
    if(depth == 0){
        cin>>root->v;
        root->l=root->r=nullptr;
        return root;
    }
    root->l=maketree(depth-1);
    root->r=maketree(depth-1);
    if(root->l->v > root->r->v) swap(root->l,root->r);
    root->v=min(root->l->v,root->r->v);
    return root;
}
void tprint(node* root,int depth)
{
    if(depth>0){
        tprint(root->l,depth-1);
        tprint(root->r,depth-1);
    }
    else{
        cout<<root->v<<" ";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    while(n--){
        buf.clear();
        int m;
        cin>>m;
        buf.reserve((1 << (m + 1)) - 1);
        node *root=maketree(m);
        tprint(root,m);
        cout << '\n';
    }
    return 0;
}