#include<bits/stdc++.h>
using namespace std;
struct node{
    int v;
    node *l,*r;
    node(int n):v(n),l(0),r(0) {}
};
node* build_tree(vector<int>& post, int post_start, int post_end, vector<int>& mid, int mid_start, int mid_end, unordered_map<int, int>& index_map) {
    if (post_start > post_end || mid_start > mid_end) {
        return nullptr;
    }
    
    int root_value = post[post_end];
    node* root = new node(root_value);
    
    int root_index = index_map[root_value];
    
    int left_size = root_index - mid_start;
    
    root->l = build_tree(post, post_start, post_start + left_size - 1, mid, mid_start, root_index - 1, index_map);
    root->r = build_tree(post, post_start + left_size, post_end - 1, mid, root_index + 1, mid_end, index_map);
    
    return root;
}
node* maketree(vector<int>& post, vector<int>& mid){
    unordered_map<int, int> index_map;
    for(int i = 0; i < mid.size(); i++) {
        index_map[mid[i]] = i;
    }
    return build_tree(post, 0, post.size() - 1, mid, 0, mid.size() - 1, index_map);
}
int main()
{
    int n;
    cin >> n;
    vector<int>post(n),mid(n);
    for(int i = 0; i < n; i++) {
        cin >> post[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> mid[i];
    }
    node* root = maketree(post, mid);
    deque<node*> q;
    cout<<root->v;
    if(root->l)
    q.push_back(root->l);
    if(root->r)
    q.push_back(root->r);
    while(!q.empty()){
        node* now = q.front();
        q.pop_front();
        cout<<" "<<now->v;
        if(now->l){
            q.push_back(now->l);
        }
        if(now->r){
            q.push_back(now->r);
        }
    }
    return 0;
}