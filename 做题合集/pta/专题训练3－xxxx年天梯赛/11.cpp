#include<bits/stdc++.h>
using namespace std;

// 定义二叉树节点结构
struct TreeNode {
    int val;            // 节点的值
    TreeNode* left;     // 左子节点指针
    TreeNode* right;    // 右子节点指针
    
    // 构造函数，创建新节点时使用
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 根据前序遍历和中序遍历构建二叉树
// preorder: 前序遍历数组 [根，左子树，右子树]
// inorder: 中序遍历数组 [左子树，根，右子树]
// preStart, preEnd: 前序遍历的起始和结束位置
// inStart, inEnd: 中序遍历的起始和结束位置
// pos: 用于快速查找节点在中序遍历中的位置
TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, 
                   vector<int>& inorder, int inStart, int inEnd,
                   unordered_map<int, int>& pos) {
    // 如果范围无效，返回空节点
    if (preStart > preEnd) {
        return NULL;
    }
    
    // 前序遍历的第一个元素是根节点
    int rootVal = preorder[preStart];
    TreeNode* root = new TreeNode(rootVal);
    
    // 找到根节点在中序遍历中的位置
    int rootPos = pos[rootVal];
    
    // 计算左子树的节点数量
    int leftSize = rootPos - inStart;
    
    // 递归构建左子树
    // 左子树在前序遍历中：[preStart+1, preStart+leftSize]
    // 左子树在中序遍历中：[inStart, rootPos-1]
    root->left = buildTree(preorder, preStart + 1, preStart + leftSize, 
                          inorder, inStart, rootPos - 1, pos);
    
    // 递归构建右子树
    // 右子树在前序遍历中：[preStart+leftSize+1, preEnd]
    // 右子树在中序遍历中：[rootPos+1, inEnd]
    root->right = buildTree(preorder, preStart + leftSize + 1, preEnd, 
                           inorder, rootPos + 1, inEnd, pos);
    
    return root;
}

// 镜面反转二叉树（只对非叶节点交换左右孩子）
void mirrorTree(TreeNode* root) {
    // 空节点不处理
    if (root == NULL) {
        return;
    }
    
    // 先递归处理左右子树
    mirrorTree(root->left);
    mirrorTree(root->right);
    
    // 如果是非叶节点（至少有一个孩子），交换左右孩子
    if (root->left != NULL || root->right != NULL) {
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

// 层序遍历（按层从上到下，每层从左到右）
vector<int> levelOrder(TreeNode* root) {
    vector<int> result;  // 存储层序遍历结果
    
    // 如果树为空，返回空结果
    if (root == NULL) {
        return result;
    }
    
    // 创建队列用于层序遍历
    queue<TreeNode*> q;
    q.push(root);  // 将根节点入队
    
    // 当队列不为空时，继续遍历
    while (!q.empty()) {
        // 取出队首节点
        TreeNode* current = q.front();
        q.pop();
        
        // 将当前节点的值加入结果
        result.push_back(current->val);
        
        // 如果左子节点存在，入队
        if (current->left != NULL) {
            q.push(current->left);
        }
        
        // 如果右子节点存在，入队
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
    
    return result;
}

int main() {
    int n;  // 节点数量
    cin >> n;
    
    // 读入中序遍历序列
    vector<int> inorder(n);
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }
    
    // 读入前序遍历序列
    vector<int> preorder(n);
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }
    
    // 创建中序遍历值到位置的映射，方便O(1)时间找到根节点位置
    unordered_map<int, int> pos;
    for (int i = 0; i < n; i++) {
        pos[inorder[i]] = i;
    }
    
    // 步骤1：根据前序和中序遍历构建二叉树
    TreeNode* root = buildTree(preorder, 0, n-1, inorder, 0, n-1, pos);
    
    // 步骤2：镜面反转二叉树
    mirrorTree(root);
    
    // 步骤3：对反转后的树进行层序遍历
    vector<int> result = levelOrder(root);
    
    // 输出层序遍历结果
    for (int i = 0; i < result.size(); i++) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    
    return 0;
}