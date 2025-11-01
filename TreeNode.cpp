#include <iostream>
#include <queue>
using namespace std;

//==========TreeNode定义及遍历算法实现==========//
//二叉树节点定义
struct TreeNode {
    int val;                // 节点数据
    TreeNode* left;          // 左子树
    TreeNode* right;         // 右子树
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}    //构造函数
};

//前序遍历【Preorder】（根-左-右）——复制
void preorder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

//中序遍历【Inorder】——BST排序
void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

//后续遍历【Postorder】——删除（释放）
void postorder(TreeNode* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

//层序遍历【Levelorder】- 用队列实现——最短路分析
void levelorder(TreeNode* root) {
    if (root == nullptr) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

// 释放整棵树（后序遍历）
void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

//用数组构造简单的二叉树（-1表示空节点）
TreeNode* buildTree(const vector<int>& vals, int index) {
    if (index >= vals.size() || vals[index] == -1) return nullptr; // -1表示空节点
    TreeNode* node = new TreeNode(vals[index]);
    node->left = buildTree(vals, 2 * index + 1);
    node->right = buildTree(vals, 2 * index + 2);
    return node;
}

int main(){
    // 示例：用数组构造一棵二叉树
    vector<int> vals = {1, 2, 3, -1, 4, 5, 6}; // -1表示空节点
    TreeNode* root = buildTree(vals, 0);

    // 构造如下树：
    //       1
    //      / \
    //     2   3
    //    /   / \
    //   4   5   6

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    cout << "Levelorder: ";
    levelorder(root);
    cout << endl;

    // 释放整棵树
    deleteTree(root);
    return 0;
}