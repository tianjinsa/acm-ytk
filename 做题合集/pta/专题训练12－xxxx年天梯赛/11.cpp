#include<bits/stdc++.h>
using namespace std;

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 使用中序和后序遍历构建二叉树
TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd, 
                   vector<int>& postorder, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) {
        return nullptr;
    }
    
    // 从后序遍历的最后一个节点获取根节点
    int rootVal = postorder[postEnd];
    TreeNode* root = new TreeNode(rootVal);
    
    // 在中序遍历中找到根节点的位置
    int rootIndexInorder = -1;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == rootVal) {
            rootIndexInorder = i;
            break;
        }
    }
    
    // 计算左子树的大小
    int leftSubtreeSize = rootIndexInorder - inStart;
    
    // 递归构建左子树和右子树
    root->left = buildTree(inorder, inStart, rootIndexInorder - 1, 
                          postorder, postStart, postStart + leftSubtreeSize - 1);
    root->right = buildTree(inorder, rootIndexInorder + 1, inEnd, 
                           postorder, postStart + leftSubtreeSize, postEnd - 1);
    
    return root;
}

// 获取树的左视图和右视图
void getTreeViews(TreeNode* root, vector<int>& leftView, vector<int>& rightView) {
    if (!root) return;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int levelSize = q.size();
        
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            
            // 左视图：每层的第一个节点
            if (i == 0) leftView.push_back(node->val);
            
            // 右视图：每层的最后一个节点
            if (i == levelSize - 1) rightView.push_back(node->val);
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
}

// 释放二叉树内存
void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> inorder(n);
    vector<int> postorder(n);
    
    // 输入中序遍历序列
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }
    
    // 输入后序遍历序列
    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }
    
    // 构建二叉树
    TreeNode* root = buildTree(inorder, 0, n - 1, postorder, 0, n - 1);
    
    // 获取左视图和右视图
    vector<int> leftView, rightView;
    getTreeViews(root, leftView, rightView);
    
    // 输出右视图
    cout << "R:";
    for (int val : rightView) {
        cout << " " << val;
    }
    cout << endl;
    
    // 输出左视图
    cout << "L:";
    for (int val : leftView) {
        cout << " " << val;
    }
    cout << endl;
    
    // 释放二叉树内存
    freeTree(root);
    
    return 0;
}