#include<bits/stdc++.h>
using namespace std;
struct node{
    int v;
    node *l,*r;
    node(int n):v(n),l(0),r(0) {}
};
node* build_tree(vector<int>& pre, int pre_start, int pre_end, vector<int>& mid, int mid_start, int mid_end, unordered_map<int, int>& index_map) {
    if (pre_start > pre_end || mid_start > mid_end) {
        return nullptr;
    }

    int root_value = pre[pre_start];
    node* root = new node(root_value);
    
    int root_index = index_map[root_value];
    
    int left_size = root_index - mid_start;

    root->l = build_tree(pre, pre_start + 1, pre_start + left_size, mid, mid_start, root_index - 1, index_map);
    root->r = build_tree(pre, pre_start + left_size + 1, pre_end, mid, root_index + 1, mid_end, index_map);

    return root;
}
node* maketree(vector<int>& pre, vector<int>& mid){
    unordered_map<int, int> index_map;
    for(int i = 0; i < mid.size(); i++) {
        index_map[mid[i]] = i;
    }
    return build_tree(pre, 0, pre.size() - 1, mid, 0, mid.size() - 1, index_map);
}
int main()
{
    int n;
    cin >> n;
    vector<int>pre(n),mid(n);
    for(int i = 0; i < n; i++) {
        cin >> mid[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    node* root = maketree(pre, mid);
    deque<node*> q;
    cout<<root->v;
    if(root->r)
    q.push_back(root->r);
    if(root->l)
    q.push_back(root->l);
    while(!q.empty()){
        node* now = q.front();
        q.pop_front();
        cout<<" "<<now->v;
        if(now->r){
            q.push_back(now->r);
        }
        if(now->l){
            q.push_back(now->l);
        }
    }
    return 0;
}